#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include "Windows.h"

DWORD WINAPI ToRecvServerThread(LPVOID lpParameter);


class ClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocket(bool &ok,int port = 4000,QString ip="127.0.0.1");
    ~ClientSocket();
    bool waitConnect(int port , QString ip);
    friend DWORD WINAPI ToRecvServerThread(LPVOID lpParameter);
    SOCKET cSock;
    void emitRecvSignal(QString);
signals:
    void recvSignal(QString);
    void connectSuccess();
    void connectSetup(QString);
    void connectFail();
public slots:
    bool sendSlot(QString);

private:
    WSADATA  Ws;
    struct sockaddr_in ServerAddr;
    
};

#endif // CLIENTSOCKET_H
