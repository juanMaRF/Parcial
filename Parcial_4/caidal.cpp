#include "caidal.h"

QRectF caidaL::boundingRect() const
{
    return QRectF(-r,-r,r*2,r*2);
}

void caidaL::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

caidaL::caidaL()
{

}

caidaL::caidaL(int x, int y)
{
    PosX=x;
    PosY=y;

    connect(timepo,SIGNAL(timeout()),this,SLOT(move()));
    timepo->start(50);

}

void caidaL::vel_act()
{
    Vel=Vel-g*delta;
}

void caidaL::move()
{
    PosY=PosY-(0.5*Vel*delta);
    setPos(PosX,PosY);
    vel_act();
}
