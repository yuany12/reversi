#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#include <QString>
#include <QLabel>
#include <QTime>

namespace Ui {
class PlayerInfo;
}

class PlayerInfo : public QLabel
{
    Q_OBJECT
    
public:
    explicit PlayerInfo(QLabel *parent = 0,bool me=true,QString name="No name");
    ~PlayerInfo();
    void setCount(QString str);
    void setCount(int i);
    void setBasicInfo(bool black, QString name);
    void setName(QString name);
    bool getBlack();
    QString getName();
    void timeZero();
    void timeadd();
private:
    Ui::PlayerInfo *ui;
    bool black;
    QString name;
    int count;
    QPixmap *map, *blackMap, *whiteMap, *blankMap;
    QTime time;
};

#endif // PLAYERINFO_H
