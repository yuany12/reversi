#include "playerinfo.h"
#include "ui_playerinfo.h"

#define BACK_PHOTO ":/new/prefix1/back.jpg"
#define BOX_PHOTO ":/new/prefix1/hezi.png"
#define BLACK_BOX_PHOTO ":/new/prefix1/heiqihe.png"
#define WHITE_BOX_PHOTO ":/new/prefix1/baiqihe.png"

PlayerInfo::PlayerInfo(QLabel *parent, bool me,QString name) :
    QLabel(parent),
    ui(new Ui::PlayerInfo)
{
    ui->setupUi(this);
    map = new QPixmap(BACK_PHOTO);
    blackMap = new QPixmap(BLACK_BOX_PHOTO);
    whiteMap = new QPixmap(WHITE_BOX_PHOTO);
    blankMap = new QPixmap(BOX_PHOTO);
    setPixmap(*map);
    ui->label->setPixmap(blankMap->scaled(ui->label->width(),ui->label->height()));
    if (me)
    {
        ui->label_2->setStyleSheet("Color:rgb(255, 170, 0);\nfont: 9pt \"華康娃娃體(P)\"");
        ui->label_3->setStyleSheet("Color:rgb(255, 170, 0);\nfont: 9pt \"華康娃娃體(P)\"");
        ui->label_4->setStyleSheet("Color:rgb(255, 170, 0);\nfont: 9pt \"華康娃娃體(P)\"");
    }
    else
    {
        ui->label_2->setStyleSheet("Color:rgb(255, 255, 255);\nfont: 9pt \"華康娃娃體(P)\"");
        ui->label_3->setStyleSheet("Color:rgb(255, 255, 255);\nfont: 9pt \"華康娃娃體(P)\"");
        ui->label_4->setStyleSheet("Color:rgb(255, 255, 255);\nfont: 9pt \"華康娃娃體(P)\"");

    }
    count = 0;
    this->name = name;
    ui->label_2->setText(name);
    QString s;
    s.setNum(count);
    ui->label_3->setText(s);
    time = QTime(0,0,0);
    ui->label_4->setText(time.toString());
}

void PlayerInfo::setBasicInfo(bool black, QString name)
{
    this->black = black;
    this->name = name;
    if (black)
        ui->label->setPixmap(blackMap->scaled(ui->label->width(),ui->label->height()));
    else ui->label->setPixmap(whiteMap->scaled(ui->label->width(),ui->label->height()));
    ui->label_2->setText(name);
}

void PlayerInfo::setCount(QString str)
{
    int c=0;
    char ch=black?'1':'2';
    for (int p=0;p<64;p++)
    {
        if (ch==str[p])
            c++;
    }
    count = c;
    QString s;
    s.setNum(count);
    ui->label_3->setText(s);

}

void PlayerInfo::setCount(int i)
{
    count = i;
    QString s;
    s.setNum(count);
    ui->label_3->setText(s);
}

PlayerInfo::~PlayerInfo()
{
    delete ui;
}

bool PlayerInfo::getBlack()
{
    return black;
}

QString PlayerInfo::getName()
{
    return name;
}

void PlayerInfo::setName(QString name)
{
    this->name=name;
}

void PlayerInfo::timeadd()
{
    time = time.addSecs(1);
    ui->label_4->setText(time.toString());

}

void PlayerInfo::timeZero()
{
    time = QTime(0,0,0);
}
