#include "serversocket.h"
#include <QtDebug>
#include <QString>
#include <iostream>
#include "Windows.h"

using namespace std;

//HANDLE cMutex;
HANDLE scEvent;

ServerSocket::ServerSocket(bool &ok, int port)
{
    int Ret = 0;

    //Init Windows Socket
    if ( WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
    {
        std::cout<<"Init Windows Socket Failed::"<<GetLastError()<<endl;
        ok = false ;
    }

    printf("服务器开始创建SOCKET\n");
    //Create Socket
    sSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( sSock == INVALID_SOCKET )
    {
        std::cout<<"Create Socket Failed::"<<GetLastError()<<endl;
        ok = false ;
    }

    LocalAddr.sin_family = AF_INET;
    char myIp[200];
    memset(myIp,0,sizeof(myIp));
//    QString ss;
    if (!getMyIp(myIp))
    {
        perror("get my ip fail!");
        ok = false ;
    }
//    strcpy(myIp ,ss.toStdString().c_str());
    printf("get ip: %s\n", myIp);
    LocalAddr.sin_addr.s_addr = inet_addr(myIp);
    LocalAddr.sin_port = htons(port);
    memset(LocalAddr.sin_zero, 0x00, 8);


    //Bind Socket
    Ret = bind(sSock, (struct sockaddr*)&LocalAddr, sizeof(LocalAddr));
    if ( Ret != 0 )
    {
        std::cout<<"Bind Socket Failed::"<<GetLastError()<<endl;
        ok = false ;
        return;
    }

    Ret = listen(sSock, 10);
    if ( Ret != 0 )
    {
        std::cout<<"listen Socket Failed::"<<GetLastError()<<endl;
        ok = false ;
        return;
    }

    std::cout<<"服务端已经启动，等待客户端连接！"<<endl;
    QString tt;
    tt.setNum(port);
    emit connectSetup( "Set up a server: " + QString::fromUtf8(myIp) + ":" + tt + "\r\n" );
    ok = true;
}

ServerSocket::~ServerSocket()
{
    closesocket(sSock);
    WSACleanup();
}

bool ServerSocket::getMyIp(char *p)
{

    char hostName[256];
    if (gethostname(hostName, sizeof(hostName))!=0)
    {
        perror("Get host name failed");
        emit connectFail();
        return false;
    }
    hostent* host_entry = gethostbyname(hostName);
    printf("%s",hostName);
    if(host_entry!=0)
    {
         int i1=host_entry->h_addr_list[0][0]&0x00ff,
             i2=host_entry->h_addr_list[0][1]&0x00ff,
             i3=host_entry->h_addr_list[0][2]&0x00ff,
             i4=host_entry->h_addr_list[0][3]&0x00ff;
         sprintf(p,"%d.%d.%d.%d\n",i1,i2,i3,i4);
         return true;
        }
    emit connectFail();
    return false;

}


bool ServerSocket::waitConnect()
{
    int AddrLen = 0;
    HANDLE hThread = NULL;
        AddrLen = sizeof(ClientAddr);
        cSock = accept(sSock, (struct sockaddr*)&ClientAddr, &AddrLen);
        if ( cSock == INVALID_SOCKET )
        {
            std::cout<<"Accept Failed::"<<GetLastError()<<endl;
            emit connectFail();
            return false;
        }

        std::cout<<"客户端连接::"<<inet_ntoa(ClientAddr.sin_addr)<<":"<<ClientAddr.sin_port<<endl;
        QString tt;
        tt.setNum(ClientAddr.sin_port);

        scEvent= CreateEvent(NULL, FALSE, FALSE, TEXT("scEvent"));
        hThread = CreateThread(NULL, 0, ::ToRecvClientThread, static_cast<LPVOID>(this), 0, NULL);
        if ( hThread == NULL )
        {
            std::cout<<"Create To Recv Thread Failed!"<<endl;
            emit connectFail();
            return false;
        }
        CloseHandle(hThread);
        WaitForSingleObject(scEvent,INFINITE); //获得进入钥匙
        emit connectSuccess();
        emit connectSetup( "Connect a client" + QString::fromUtf8(inet_ntoa(ClientAddr.sin_addr))+":"+ tt + "\r\n" );

        return true;
}




DWORD WINAPI ToRecvClientThread(LPVOID lpParameter)
{
    ServerSocket *sscock = static_cast<ServerSocket *>(lpParameter);
    SOCKET ClientSocket = sscock->cSock;
    int Ret = 0;
    char RecvBuffer[MAX_PATH];
    SetEvent(scEvent);
    while ( true )
    {
        memset(RecvBuffer, 0x00, sizeof(RecvBuffer));
        Ret = recv(ClientSocket, RecvBuffer, MAX_PATH, 0);
        if ( Ret == 0 || Ret == SOCKET_ERROR )
        {
            std::cout<<"客户端退出!"<<endl;
            break;
        }
        std::cout << "get mes: " << RecvBuffer << std::endl;
        QString tmp(RecvBuffer);
        sscock->emitRecvSignal(tmp);
    }

//    ::ReleaseMutex(cMutex);
    return 0;
}

bool ServerSocket::sendSlot(QString mes)
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
                cout<<"Send Out::"<<SendBuffer << endl;
    }
    return true;

}


void ServerSocket::emitRecvSignal(QString str)
{
    emit recvSignal(str);
}
