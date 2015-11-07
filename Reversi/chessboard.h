#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QLabel>

class ChessBoard : public QLabel
{
    Q_OBJECT
public:
    explicit ChessBoard(QLabel *parent = 0);
    ~ChessBoard();
    void setBlack(bool);
    void setPutEnabled(bool);
    void reset();
signals:
    void newChess(QString);
    void gameOver(int);
public slots:
    void getNewChess(QString);//1 blank 2 white 0 blank
    void getStart();
    void setInp(bool);
private:
    QPixmap *map, *blackChess, *whiteChess, *inpChess;
    bool isBlack;
    QString myBoardInfo;
    bool wantPut(QPoint);
    int checkWinner(int);
    bool putEnabled;
    bool inp;
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *ev);
};

#endif // CHESSBOARD_H
