#ifndef TIRO_PARA_H
#define TIRO_PARA_H


#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <math.h>
#include <QDebug>

class tiro_para:public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    double pos_inicial;
    double g= -9.8;
    double delta =0.1;
    double posy,posx, ang=50, vel, vel_x=30, vel_y=30;
    int r=8,con=0,tipo1;
    QTimer *timepo=new QTimer();
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    tiro_para(int x,int y, int tipo,int a);
    void ActualizarVelocidad();

    double getPosy() const;
    void setPosy(double value);

    double getPosx() const;
    void setPosx(double value);

    double getVel_x() const;
    void setVel_x(double value);

    double getVel_y() const;
    void setVel_y(double value);

private slots:
    void ActualizarPosicion();

};

#endif // TIRO_PARA_H
