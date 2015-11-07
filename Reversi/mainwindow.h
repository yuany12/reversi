#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Windows.h>
#include <QTimer>
#include <QCloseEvent>
#include "chessboard.h"
#include "clientsocket.h"
#include "serversocket.h"
#include "playerinfo.h"

DWORD WINAPI ServerThread(LPVOID lpParameter);
DWORD WINAPI ClientThread(LPVOID lpParameter);


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    friend DWORD WINAPI ServerThread(LPVOID lpParameter);
    friend DWORD WINAPI ClientThread(LPVOID lpParameter);
    ServerSocket *myServerSocket;
    ClientSocket *myClientSocket;
private slots:
    void start();
    void newChessSlot(QString);
    void gameOverSlot(int);
    void recvSlot(QString );
    void on_pushButton_set_clicked();
    void on_pushButton_con_clicked();
    void on_pushButton_los_clicked();
    void on_pushButton_agn_clicked();
    void on_pushButton_lea_clicked();
    void on_pushButton_inp_clicked();
    void on_lineEdit_returnPressed();
    void timeadd();
    void connectSlot(QString);
    void connectFail();
protected:
    void closeEvent(QCloseEvent *);
private:
    Ui::MainWindow *ui;
    ChessBoard *chessBoard;
    QLayout *boardLayout;
    QLabel *label;
    QPixmap *backPic;
    HANDLE clientMutex;
    int black,nowTurn; //black1 white2 blank0
    QString MyName,HisName;
    PlayerInfo *myInfo, *hisInfo;
    QTimer *timer;
    bool isInGame;
signals:
    void sendInf(QString);
    void sendMes(QString);
    void sendBoa(QString);

};

#endif // MAINWINDOW_H
