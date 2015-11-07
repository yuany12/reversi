#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include "Windows.h"
#include <QString>
#include <QObject>

DWORD WINAPI ToRecvClientThread(LPVOID lpParameter);


class ServerSocket : public QObject
{
    Q_OBJECT
public:
    ServerSocket(bool &ok,int port=4000);
    ~ServerSocket();
    friend DWORD WINAPI ToRecvClientThread(LPVOID lpParameter);
    bool waitConnect();
    void emitRecvSignal(QString);
    SOCKET cSock;
    bool getMyIp(char *p);
private:
    WSADATA  Ws;
    SOCKET sSock;
    struct sockaddr_in LocalAddr, ClientAddr;

signals:
    void recvSignal(QString);
    void connectSuccess();
    void connectSetup(QString);
    void connectFail();
public slots:
//    void recvSlot(QString);
    bool sendSlot(QString);
};

#endif // SERVERSOCKET_H
