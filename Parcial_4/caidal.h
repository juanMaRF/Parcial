#ifndef CAIDAL_H
#define CAIDAL_H
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QPainter>
#include <math.h>
#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <math.h>
#include <QDebug>


class caidaL:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    caidaL(int x,QGraphicsItem * parent=0);
    void actu_vel();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

private slots:
    void move();

private:
    short con=0;
    double pos_inicial;
    double g= 9.8;
    double PosY,PosX, h, w,Vel,delta=0.5;
    int r=10;
};

#endif // CAIDAL_H
