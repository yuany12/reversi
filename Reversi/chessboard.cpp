#include "chessboard.h"
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>

#include <QtDebug>

#define CHESS_BOARD_ADDRESS ":/new/prefix1/chessboard.png"
#define BLACK_CHESS ":/new/prefix1/heiqi.png"
#define WHITE_CHESS ":/new/prefix1/baiqi.png"
#define INP_CHESS ":/new/prefix1/inp.png"

int dirx[8] = {-1,-1,0,1,1,1,0,-1};
int diry[8] = {0,1,1,1,0,-1,-1,-1};

ChessBoard::ChessBoard(QLabel *parent) :
    QLabel(parent),putEnabled(false)
{
    map = new QPixmap(CHESS_BOARD_ADDRESS);
    blackChess = new QPixmap(BLACK_CHESS);
    whiteChess = new QPixmap(WHITE_CHESS);
    inpChess = new QPixmap(INP_CHESS);;
    this->setPixmap(*map);
    myBoardInfo = "00000000"
                  "00000000"
                  "00000000"
                  "00012000"
                  "00021000"
                  "00000000"
                  "00000000"
                  "00000000";
    inp = false;
}

ChessBoard::~ChessBoard()
{
    delete map;
}

void ChessBoard::getNewChess(QString boardInfo)
{
     myBoardInfo = boardInfo;
     putEnabled = true;
     update();
     int ret;
     if ((ret=checkWinner(isBlack?1:2))!=0)
     {
         putEnabled = false;
         emit gameOver(ret);
     }
}

void ChessBoard::getStart()
{
    getNewChess("00000000"
            "00000000"
            "00000000"
            "00012000"
            "00021000"
            "00000000"
            "00000000"
            "00000000");
}


int ChessBoard::checkWinner(int player)
{
    bool flag=false;
    int count[3];
    count[0] = count[1] = count[2] = 0;
    for (int p=0;p<64;p++)
    {
        if (myBoardInfo[p]=='0')
            count[0]++;
        if (myBoardInfo[p]=='1')
            count[1]++;
        if (myBoardInfo[p]=='2')
            count[2]++;
    }
    if (count[0]==0)
    {
        if (count[1]>count[2]) return 1;
        if (count[1]==count[2]) return 3;
        if (count[1]<count[2]) return 2;
    }
    for (int p=0;p<64;p++)
    {
        if (myBoardInfo[p]!='0')
            continue;
        int sx = p/8;
        int sy = p%8;

        for (int i=0;i<8;i++)
        {
            int t=1;
            char my = (player==1)?'1':'2';
            char his = (player==1)?'2':'1';
            while (sx+dirx[i]*t>=0 && sx+dirx[i]*t<8
                   && sy+diry[i]*t>=0 && sy+diry[i]*t<8
                   && myBoardInfo[(sx+dirx[i]*t)*8+sy+diry[i]*t]==his)
                t++;
            if (t>1 && sx+t*dirx[i]>=0 && sx+t*dirx[i]<8
                && sy+t*diry[i]>=0 && sy+t*diry[i]<8 &&
                    myBoardInfo[(sx+dirx[i]*t)*8+sy+diry[i]*t]==my)
            {
                flag = true;
                return 0;
            }
        }
    }
    return 3-player;
}

void ChessBoard::setBlack(bool flag)
{
    isBlack = flag;
}

void ChessBoard::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,*map);
    painter.translate(25,26);
    for (int i=0;i<64;i++)
    {
        painter.save();
        int x = i / 8;
        int y = i % 8;
        painter.translate(56*x, 56*y);
        if (myBoardInfo[i]=='1')
            painter.drawPixmap(0,0,*blackChess);
        else if (myBoardInfo[i]=='2')
            painter.drawPixmap(0,0,*whiteChess);
        painter.restore();
    }
    if (inp)
    {
        for (int p=0;p<64;p++)
        {
            if (myBoardInfo[p]!='0')
                continue;
            int sx = p/8;
            int sy = p%8;
            bool flag=false;
            for (int i=0;i<8;i++)
            {
                int t=1;
                char my = (isBlack)?'1':'2';
                char his = (isBlack)?'2':'1';
                while (sx+dirx[i]*t>=0 && sx+dirx[i]*t<8
                       && sy+diry[i]*t>=0 && sy+diry[i]*t<8
                       && myBoardInfo[(sx+dirx[i]*t)*8+sy+diry[i]*t]==his)
                    t++;
                if (t>1 && sx+t*dirx[i]>=0 && sx+t*dirx[i]<8
                    && sy+t*diry[i]>=0 && sy+t*diry[i]<8 &&
                        myBoardInfo[(sx+dirx[i]*t)*8+sy+diry[i]*t]==my)
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                continue;
            painter.save();
            painter.translate(56*sx,56*sy);
            painter.drawPixmap(0,0,inpChess->scaled(46,46));
            painter.restore();
        }
    }
}

void ChessBoard::mousePressEvent(QMouseEvent *ev)
{
    if (!putEnabled)
        return;
    if (ev->button()==Qt::LeftButton)
    {
        int sx = (ev->pos().x() - 21) / 56;
        int sy = (ev->pos().y() - 22) / 56;
        if (sx>=0 && sx<8 &&
            sy>=0 && sy<8)
        {
            QPoint point(sx,sy);
            if (wantPut(point))
            {
                inp = false;
                update();
                int ret;
                putEnabled = false;
                if ((ret=checkWinner(isBlack?2:1))!=0)
                {
                    emit newChess(myBoardInfo);
                    emit gameOver(ret);
                }
                else
                {
                    emit newChess(myBoardInfo);
                }
            }
        }
    }
}

bool ChessBoard::wantPut(QPoint point)
{
    int sx=point.x(),sy=point.y();
    if (myBoardInfo[sx*8+sy]!='0')
        return false;
    bool flag=false;
    char my = isBlack?'1':'2';
    char his = isBlack?'2':'1';
    for (int i=0;i<8;i++)
    {
        int t=1;

        while (sx+dirx[i]*t>=0 && sx+dirx[i]*t<8
               && sy+diry[i]*t>=0 && sy+diry[i]*t<8
               && myBoardInfo[(sx+dirx[i]*t)*8+sy+diry[i]*t]==his)
            t++;
        if (t>1 && sx+t*dirx[i]>=0 && sx+t*dirx[i]<8
                && sy+t*diry[i]>=0 && sy+t*diry[i]<8 &&
                myBoardInfo[(sx+dirx[i]*t)*8+sy+diry[i]*t]==my)
        {
            flag = true;
            for (int j=1;j<t;j++)
            {
                myBoardInfo[(sx+j*dirx[i])*8+sy+j*diry[i]]=my;
            }
        }
    }
    if (flag)
    {
        myBoardInfo[sx*8+sy]=my;
        return true;
    }
    return false;
}

void ChessBoard::setPutEnabled(bool flag)
{
    putEnabled = flag;
}

void ChessBoard::setInp(bool flag)
{
    inp = flag;
    update();
}

void ChessBoard::reset()
{
    myBoardInfo = "00000000"
                  "00000000"
                  "00000000"
                  "00012000"
                  "00021000"
                  "00000000"
                  "00000000"
                  "00000000";
    update();
}
