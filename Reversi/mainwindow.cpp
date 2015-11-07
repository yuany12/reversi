#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serversocket.h"
#include "clientsocket.h"
#include "portdialog.h"
#include "connectdialog.h"
#include <Windows.h>
#include <QLabel>
#include <QHBoxLayout>
#include <QRect>
#include <QPixmap>
#include <QString>
#include <QStringList>
#include <QObject>
#include <QtDebug>
#include <QInputDialog>
#include <QLineEdit>
#include <QTextBrowser>
#include <QString>
#include <QMessageBox>

bool canExit;
HANDLE mutex;
#define BACK_PHOTO_PATH ":/new/prefix1/back.jpg"
#define BUTTON_PHOTO_PATH ":/new/prefix1/buttons.jpg"
#define BLACK_PATH ":/new/prefix1/pureblack.jpg"
#define BOX_PATH ":/new/prefix1/hezi.png"

#define BORAD_WIDTH 488
#define BOARD_HEIGHT 494

HANDLE hMutex;

MainWindow *mw;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    myServerSocket(NULL),
    myClientSocket(NULL)
{
    mw = this;
    canExit = false;
    ui->setupUi(this);

    bool ok = false;
    setWindowTitle("Reversi");
    QIcon icon(BOX_PATH);
    setWindowIcon(icon);

    QString text = QInputDialog::getText(this,"Your name?", "Please input your name^_^",
                      QLineEdit::Normal, QString::null, &ok );
    if ( ok && !text.isEmpty() )
        MyName=text;
    else
        MyName="No Name";
    chessBoard = new ChessBoard(ui->chessLabel);
    backPic = new QPixmap(BACK_PHOTO_PATH);
    ui->backLabel->setPixmap(backPic->scaled(ui->backLabel->width(),ui->backLabel->width()));
    ui->statusBar->setStyleSheet("background-image: url("  BACK_PHOTO_PATH  ")");
    ui->pushButton_set->setStyleSheet("background-image: url("  BACK_PHOTO_PATH  ");"
                                      );
    ui->pushButton_con->setStyleSheet("background-image: url("  BACK_PHOTO_PATH  ");"
                                      );
    ui->pushButton_agn->setStyleSheet("background-image: url("  BACK_PHOTO_PATH  ");"
                                      );
    ui->pushButton_los->setStyleSheet("background-image: url("  BACK_PHOTO_PATH  ");"
                                      );
    ui->pushButton_inp->setStyleSheet("background-image: url("  BACK_PHOTO_PATH  ");"
                                      );
    ui->pushButton_lea->setStyleSheet("background-image: url("  BACK_PHOTO_PATH  ");"
                                      );
    ui->lineEdit->setStyleSheet("background-image: url("  BLACK_PATH  ");"
                                "color:rgb(255, 170, 0);"
                                "font: 9pt \"華康娃娃體(P)\";");
    ui->textBrowser->setStyleSheet("background-image: url("  BLACK_PATH  ");"
                                "color:rgb(255, 170, 0);"
                                "font: 9pt \"華康娃娃體(P)\";");
    ui->statusBar->setStyleSheet("background-image: url("  BACK_PHOTO_PATH  ");"
                                 "color:rgb(255, 170, 0);"
                                 "font: 9pt \"華康娃娃體(P)\";");

    ui->pushButton_agn->setEnabled(false);
    ui->pushButton_inp->setEnabled(false);
    ui->pushButton_los->setEnabled(false);

    hisInfo = new PlayerInfo(ui->label_3,false,"----");
    myInfo = new PlayerInfo(ui->label_4,true,MyName);

    black = 0;
    update();
    connect(chessBoard, SIGNAL(newChess(QString)),
            this,SLOT(newChessSlot(QString)));
    connect(chessBoard, SIGNAL(gameOver(int)),
            this,SLOT(gameOverSlot(int)));
    isInGame = false;

    hMutex = CreateMutex(NULL,FALSE,TEXT("myMutex"));

    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),
            this,SLOT(timeadd()));

}

MainWindow::~MainWindow()
{
    canExit = true;
    delete chessBoard;
    delete ui;
}

DWORD WINAPI ServerThread(LPVOID lpParameter)
{
    int ret = (int)lpParameter;
    bool ok = false;
    mw->myServerSocket = new ServerSocket(ok,ret);
    if (!ok)
    {
        delete mw->myServerSocket;
        mw->myServerSocket = NULL;

        canExit = false;

//        QMessageBox::information(0,"Fail","Create Thread Failed",QMessageBox::Ok);
        return 1;
    }
    mw->connect(mw->myServerSocket,SIGNAL(connectSuccess()),
                 mw,SLOT(start()));
    mw->connect(mw->myServerSocket,SIGNAL(connectFail()),
                mw,SLOT(connectFail()));
    mw->connect(mw->myServerSocket,SIGNAL(recvSignal(QString)),
                 mw,SLOT(recvSlot(QString)));
    mw->connect(mw,SIGNAL(sendInf(QString)),
                 mw->myServerSocket,SLOT(sendSlot(QString)));
    mw->connect(mw,SIGNAL(sendMes(QString)),
                 mw->myServerSocket,SLOT(sendSlot(QString)));
    mw->connect(mw,SIGNAL(sendBoa(QString)),
                 mw->myServerSocket,SLOT(sendSlot(QString)));
    if (!mw->myServerSocket->waitConnect())
    {
        delete mw->myServerSocket;
        mw->myServerSocket = NULL;

        canExit = false;

        return 1;
    }
    while (!canExit);
    delete (mw->myServerSocket);
    mw->myServerSocket = NULL;

    canExit = false;
    ::ReleaseMutex(hMutex);
    return 0;
}

DWORD WINAPI ClientThread(LPVOID lpParameter)
{
    mw->connect(mw->myClientSocket,SIGNAL(connectFail()),
                mw,SLOT(connectFail()));
    int* par = (int*)lpParameter;
    QString tmp1="",tmp2="";
    for (int i=0;i<4;i++,par++)
    {
        int a = *par;
        tmp2.setNum(a);
        tmp1 += tmp2;
        if (i!=3)
            tmp1 += ".";
    }
    bool ok;
    mw->myClientSocket = new ClientSocket(ok,*par,tmp1);
    if (!ok)
    {
        delete (mw->myClientSocket);
        mw->myClientSocket = NULL;
        canExit = false;
        return 1;
    }
    mw->connect(mw->myClientSocket,SIGNAL(connectSuccess()),
                 mw,SLOT(start()));
    mw->connect(mw->myClientSocket,SIGNAL(connectFail()),
                mw,SLOT(connectFail()));
    mw->connect(mw->myClientSocket,SIGNAL(recvSignal(QString)),
                 mw,SLOT(recvSlot(QString)));
    mw->connect(mw->myClientSocket,SIGNAL(connectSetup(QString)),
                mw,SLOT(connectSlot(QString)));
    mw->connect(mw,SIGNAL(sendInf(QString)),
                 mw->myClientSocket,SLOT(sendSlot(QString)));
    mw->connect(mw,SIGNAL(sendMes(QString)),
                 mw->myClientSocket,SLOT(sendSlot(QString)));
    mw->connect(mw,SIGNAL(sendBoa(QString)),
                 mw->myClientSocket,SLOT(sendSlot(QString)));
    if (!mw->myClientSocket->waitConnect(*par,tmp1))
    {
        delete (mw->myClientSocket);
        mw->myClientSocket = NULL;
        canExit = false;
        return 1;
    }
    while (!canExit);
    delete (mw->myClientSocket);
    mw->myClientSocket = NULL;

    ::ReleaseMutex(hMutex);
    canExit = false;
    return 0;
}

void MainWindow::on_pushButton_set_clicked()
{    
    PortDialog dlg;
    if ( dlg.exec()==QDialog::Accepted)
    {
        if (this->myServerSocket || this->myClientSocket )
            canExit = true;
        else canExit = false;
        while (canExit)
            Sleep(1000);
        int ret;
        if ((ret=dlg.getPort())!=-1)
        {
            HANDLE hThread = CreateThread(NULL, 0, ::ServerThread, (LPVOID)ret, 0, NULL);

            if (hThread !=NULL)
            {
                CloseHandle(hThread);
                chessBoard->setBlack(dlg.getBlack());
                black = dlg.getBlack()?1:2;
                ui->pushButton_set->setEnabled(false);
                ui->pushButton_con->setEnabled(false);
                myInfo->timeZero();
                hisInfo->timeZero();
            }
            else
            {
                perror("Create Thread Failed!");
                canExit = true;
                QMessageBox::information(this,"Fail","Create Thread Failed",QMessageBox::Ok);
            }
        }
        else
        {
            canExit = true;
            QMessageBox::information(this,"Fail","Create Thread Failed",QMessageBox::Ok);
        }

    }
}

void MainWindow::on_pushButton_con_clicked()
{
    ConnectDialog dlg;
    int *to;
    to = new int[5];
    if ( dlg.exec()==QDialog::Accepted)
    {
        if (this->myServerSocket || this->myClientSocket )
            canExit = true;
        else canExit = false;
        while (canExit)
            Sleep(1000);
        int ret;
        QString rr;
        if ((ret=dlg.getPort())!=-1 && dlg.getIP(rr))
        {
            QStringList list = rr.split(".");
            to[0] = list[0].toInt();
            to[1] = list[1].toInt();
            to[2] = list[2].toInt();
            to[3] = list[3].toInt();
            to[4] = ret;

            HANDLE hThread = CreateThread(NULL, 0, ::ClientThread, (LPVOID)to, 0, NULL);

            if (hThread !=NULL)
            {
                CloseHandle(hThread);
                ui->pushButton_set->setEnabled(false);
                ui->pushButton_con->setEnabled(false);
                myInfo->timeZero();
                hisInfo->timeZero();

                black = 0;
            }
            else {
                    perror("Create Thread Failed!");
                    canExit = true;
                    QMessageBox::information(this,"Fail","Create Thread Failed",QMessageBox::Ok);
                 }
        }
        else
        {
            canExit = true;
            QMessageBox::information(this,"Fail","Create Thread Failed",QMessageBox::Ok);
        }
    }
}

void MainWindow::start()
{
    ui->pushButton_con->setEnabled(false);
    ui->pushButton_set->setEnabled(false);

    QString tmp="inf#",nb;
    nb.setNum(black);
    tmp+=nb;
    tmp+="#";
    tmp+=MyName;
    tmp+="#";

    if (this->myServerSocket)
    {
        this->myServerSocket->sendSlot(tmp);
    }
    else if (this->myClientSocket)
    {
        this->myClientSocket->sendSlot(tmp);
    }

}

void MainWindow::newChessSlot(QString str)
{
    QString tmp="boa#"+str+"#";
    if (this->myServerSocket)
    {
        myInfo->setCount(tmp);
        hisInfo->setCount(tmp);
        this->myServerSocket->sendSlot(tmp);
    }
    else if (this->myClientSocket)
    {
        myInfo->setCount(tmp);
        hisInfo->setCount(tmp);
        this->myClientSocket->sendSlot(tmp);
    }
    ui->statusBar->showMessage("His Turn!");
    nowTurn = 3-black;
    ui->pushButton_inp->setEnabled(false);
}

void MainWindow::gameOverSlot(int i)
{
    isInGame = false;
    chessBoard->setPutEnabled(false);
    ui->pushButton_los->setEnabled(false);
    ui->pushButton_con->setEnabled(true);
    ui->pushButton_set->setEnabled(true);
    ui->pushButton_agn->setEnabled(true);

    timer->stop();

    if (i==black)
    {
        ui->textBrowser->setText(ui->textBrowser->toPlainText() + "----You win!!----\r\n");
        QMessageBox::information(this,"Game Over","You win!!");
    }
    else if (i==3-black)
    {
        ui->textBrowser->setText(ui->textBrowser->toPlainText() + "----You lose..----\r\n");
        QMessageBox::information(this,"Game Over","You lose..");
    }
    else if (i==3)
    {
        ui->textBrowser->setText(ui->textBrowser->toPlainText() + "----Draw----\r\n");
        QMessageBox::information(this,"Game Over","Draw");
    }
}

void MainWindow::recvSlot(QString dat)
{

    if (dat.section('#',0,0)=="inf")
    {
        HisName = QString::fromUtf8(dat.section('#',2,2).toStdString().c_str());
        if (black)
        {
            if (black==1)
            {
                myInfo->setBasicInfo(true,MyName);
                hisInfo->setBasicInfo(false,HisName);
            }
            else if (black==2)
            {
                myInfo->setBasicInfo(false,MyName);
                hisInfo->setBasicInfo(true,HisName);
            }
            myInfo->setCount(2);
            hisInfo->setCount(2);
        }
        else if (dat.section('#',1,1)=="1")
        {
            black = 2;
            myInfo->setBasicInfo(false,MyName);
            hisInfo->setBasicInfo(true,HisName);
            myInfo->setCount(2);
            hisInfo->setCount(2);
            chessBoard->setBlack(false);
        }
        else if (dat.section('#',1,1)=="2")
        {
            black = 1;
            myInfo->setBasicInfo(true,MyName);
            hisInfo->setBasicInfo(false,HisName);
            myInfo->setCount(2);
            hisInfo->setCount(2);
            chessBoard->setBlack(true);
        }
        else if (dat.section('#',1,1)=="0")
        {
            if (black==1)
            {
                myInfo->setBasicInfo(true,MyName);
                hisInfo->setBasicInfo(false,HisName);
                myInfo->setCount(2);
                hisInfo->setCount(2);
            }
            else if (black==2)
            {
                myInfo->setBasicInfo(false,MyName);
                hisInfo->setBasicInfo(true,HisName);
                myInfo->setCount(2);
                hisInfo->setCount(2);

            }
        }
        ui->textBrowser->setText(ui->textBrowser->toPlainText() +  "New Game Starts!!\r\n");
        nowTurn = 1;
        timer->start(1000);
        ui->pushButton_agn->setEnabled(false);
        ui->pushButton_los->setEnabled(true);
        isInGame = true;
        if (black==1)
        {
            ui->statusBar->showMessage("Your Turn!");
            chessBoard->getStart();
        }
        else
        {
            ui->statusBar->showMessage("His Turn!");
        }
    }
    else if (dat.section('#',0,0)=="boa")
    {
        nowTurn = black;
        ui->statusBar->showMessage("Your Turn!");
        ui->pushButton_inp->setEnabled(true);
        myInfo->setCount(dat.section('#',1,1));
        hisInfo->setCount(dat.section('#',1,1));
        chessBoard->getNewChess(dat.section('#',1,1));
    }
    else if (dat.section("#",0,0)=="mes")
    {
        dat.section("#",1,1);
        QString tt="";
        if (black==1)
            tt="(W)";
        if (black==2)
            tt="(B)";
        ui->textBrowser->setText(ui->textBrowser->toPlainText() + HisName + tt + ":"+QString::fromUtf8(dat.section("#",1,1).toStdString().c_str())  + "\r\n");
    }
    else if (dat.section("#",0,0)=="los")
    {
        gameOverSlot(black);
    }
    else if (dat.section("#",0,0)=="wag")
    {
        if ( QMessageBox::Ok==QMessageBox::information(this,"Again?","The other player wants to play again. Ok?",QMessageBox::Ok,QMessageBox::Cancel))
        {
            if (this->myServerSocket)
            {
                this->myServerSocket->sendSlot("agn#");

            }
            else if (this->myClientSocket)
            {
                this->myClientSocket->sendSlot("agn#");
            }
            start();
        }

    }
    else if (dat.section("#",0,0)=="agn")
    {
        start();
    }
    else if (dat.section("#",0,0)=="wby")
    {
        ui->pushButton_agn->setEnabled(false);
        if (this->myServerSocket)
        {
            this->myServerSocket->sendSlot("bye#");
            canExit = true;
            gameOverSlot(black);

        }
        else if (this->myClientSocket)
        {
            this->myClientSocket->sendSlot("bye#");

            canExit = true;
            gameOverSlot(black);
        }
    }
    else if (dat.section("#",0,0)=="bye")
    {
        ui->pushButton_agn->setEnabled(false);
        if (this->myServerSocket)
        {
            canExit = true;
            qApp->quit();
        }
        else if (this->myClientSocket)
        {
            canExit = true;
            qApp->quit();
        }
    }
}

void MainWindow::on_lineEdit_returnPressed()
{
    if (ui->lineEdit->text().isEmpty() && ui->lineEdit->text().indexOf("#")==-1)
        return;
    QString tt="";
    if (black==1)
        tt="(B)";
    if (black==2)
        tt="(W)";
    ui->textBrowser->setText(ui->textBrowser->toPlainText() + MyName+ tt + ":"+ui->lineEdit->text() + "\r\n");
    if (this->myServerSocket)
    {
        this->myServerSocket->sendSlot("mes#"+ui->lineEdit->text()+"#");
    }
    else if (this->myClientSocket)
    {
        this->myClientSocket->sendSlot("mes#"+ui->lineEdit->text()+"#");
    }
    ui->lineEdit->clear();

}

void MainWindow::on_pushButton_los_clicked()
{
    QString tmp = "los#";
    if (this->myServerSocket)
    {
        this->myServerSocket->sendSlot(tmp);
    }
    else if (this->myClientSocket)
    {
        this->myClientSocket->sendSlot(tmp);
    }
    gameOverSlot(3-black);
}

void MainWindow::on_pushButton_inp_clicked()
{
    if (nowTurn==black)
        chessBoard->setInp(true);
}

void MainWindow::timeadd()
{
    if (nowTurn==black)
        myInfo->timeadd();
    else hisInfo->timeadd();
}

void MainWindow::on_pushButton_agn_clicked()
{
    if (this->myServerSocket)
    {
        if (!this->myServerSocket->sendSlot("tst"))
        {
            ui->pushButton_agn->setEnabled(false);
            return;
        }
    }
    else if (this->myClientSocket)
    {
        if (!this->myClientSocket->sendSlot("tst"))
        {
            ui->pushButton_agn->setEnabled(false);
            return;
        }
    }
    if (this->myServerSocket)
    {
        this->myServerSocket->sendSlot("wag");
    }
    else if (this->myClientSocket)
    {
        this->myClientSocket->sendSlot("wag");
    }
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if (!isInGame)
        return;
    if (this->myServerSocket)
    {
        if (!this->myServerSocket->sendSlot("tst"))
            return;
    }
    else if (this->myClientSocket)
    {
        if (!this->myClientSocket->sendSlot("tst"))
            return;
    }
    if (QMessageBox::Yes==QMessageBox::warning(this,"close","Do you want to leave the game?",QMessageBox::Yes,QMessageBox::No))
    {
        if (this->myServerSocket)
        {
            if (!this->myServerSocket->sendSlot("wby"))
                return;
        }
        else if (this->myClientSocket)
        {
            if (!this->myClientSocket->sendSlot("wby"))
                return;
        }
    }
    e->ignore();
}

void MainWindow::on_pushButton_lea_clicked()
{
    close();
}

void MainWindow::connectSlot(QString str)
{
    ui->textBrowser->setText(ui->textBrowser->toPlainText() + str);
}

void MainWindow::connectFail()
{
    QMessageBox::information(this,"Fail","Connect failed..");
    ui->pushButton_set->setEnabled(true);
    ui->pushButton_con->setEnabled(true);
}
