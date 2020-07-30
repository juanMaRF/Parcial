#ifndef CAIDAL_H
#define CAIDAL_H
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QPainter>
#include <math.h>

class caidaL:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

    caidaL();
    caidaL(int x,int y);
    void vel_act();

private slots:
    void move();
private:
    QTimer *timepo=new QTimer();
    short con=0;
    double pos_inicial;
    double g= 9.8;
    double PosY,PosX, h, w,Vel,delta=0.5;
    int r=8;
};

#endif // CAIDAL_H
