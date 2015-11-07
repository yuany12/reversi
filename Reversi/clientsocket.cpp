#include "clientsocket.h"
#include <QtDebug>
#include <iostream>
#include "Windows.h"

using namespace std;

//ClientSocket* par;
HANDLE cEvent;

ClientSocket::ClientSocket(bool &ok,int port , QString ip)
{
    int Ret = 0;
    int AddrLen = 0;
    //Init Windows Socket
    if ( WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
    {
        cout<<"Init Windows Socket Failed::"<<GetLastError()<<endl;
        emit connectFail();
        ok = false ;
        return;
    }

    //Create Socket
    cSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( cSock == INVALID_SOCKET )
    {
        cout<<"Create Socket Failed::"<<GetLastError()<<endl;
        ok =false;
        emit connectFail();
        return;
    }

    ok = true;

}


bool ClientSocket::waitConnect(int port , QString ip)
{
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.s_addr = inet_addr(ip.toStdString().c_str());
    ServerAddr.sin_port = htons(port);
    memset(ServerAddr.sin_zero, 0x00, 8);

    int Ret = ::connect(cSock,(struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
    if ( Ret == SOCKET_ERROR )
    {
        cout<<"Connect Error::"<<GetLastError()<<endl;
        emit connectFail();
        return false;
    }
    else
    {
        cout<<"连接成功! 等待消息输入"<<endl;
    }
    QString tt;
    tt.setNum(port);
    emit connectSetup("Connect successfully with " + ip + ":" + tt + "\r\n");
    cEvent= CreateEvent(NULL, FALSE, FALSE, TEXT("cevent"));
    HANDLE hThread = CreateThread(NULL, 0, ::ToRecvServerThread, static_cast<LPVOID>(this), 0, NULL);
    if ( hThread == NULL )
    {
        std::cout<<"Create To Recv Thread Failed!"<<endl;
        emit connectFail();
        return false;
    }
    CloseHandle(hThread);

    WaitForSingleObject(cEvent,INFINITE); //获得进入钥匙
    if (!sendSlot("tst"))
    {
        emit connectFail();
        return false;
    }
    emit connectSuccess();
    return true;
}

ClientSocket::~ClientSocket()
{
    closesocket(cSock);
    WSACleanup();
}

DWORD WINAPI ToRecvServerThread(LPVOID lpParameter)
{
    char RecvBuffer[MAX_PATH];
    int Ret;
    ClientSocket *cs = static_cast<ClientSocket *>(lpParameter);

    SOCKET ccSock = cs->cSock;
    qDebug() << cs->cSock;
    SetEvent(cEvent);
    while ( true )
    {
        memset(RecvBuffer,0x00,8);
        Ret = recv(ccSock, RecvBuffer, MAX_PATH, 0);

        if ( Ret == SOCKET_ERROR || Ret == 0 )
        {
            return 1;
        }
        else
        {
            cout<<"Recv::"<<endl;
            cout << RecvBuffer << endl;
            QString tmp(RecvBuffer);
            cs->emitRecvSignal(tmp);
        }
    }
    return 0;
}

bool ClientSocket::sendSlot(QString mes)
{
    char SendBuffer[MAX_PATH];
    memset(SendBuffer,0x00,8);
    int i;
    for (i=0;i<MAX_PATH&&i<mes.size();i++)
    {
        cout << (SendBuffer[i]=mes.toStdString()[i]);
    }
    SendBuffer[i]='\0';

    int Ret = send(cSock, SendBuffer, MAX_PATH, 0);
    if ( Ret == SOCKET_ERROR )
        {
                cout<<"Send Info Error::"<<GetLastError()<<endl;
                return false;
        }
    else
    {
                cout<<"Send Out::"<<  SendBuffer << endl;
    }
    return true;
}


void ClientSocket::emitRecvSignal(QString str)
{
    qDebug() << "revc " << str;
    emit recvSignal(str);
}
