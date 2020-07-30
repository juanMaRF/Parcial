#include "tiro_para.h"



double tiro_para::getPosy() const
{
    return posy;
}

void tiro_para::setPosy(double value)
{
    posy = value;
}

double tiro_para::getPosx() const
{
    return posx;
}

void tiro_para::setPosx(double value)
{
    posx = value;
}

void tiro_para::ActualizarPosicion()
{
    posx=posx+vel_x*delta;
    posy=posy+vel_y*delta-(0.5*g*pow(delta,2));
    setPos(posx,posy);
}

QRectF tiro_para::boundingRect() const
{
    return QRectF(-r,-r,r*2,r*2);
}

void tiro_para::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

tiro_para::tiro_para(int x, int y)
{
    posx=x;
    posy=y;

    connect(timepo,SIGNAL(timeout()),this,SLOT(ActualizarPosicion()));
    timepo->start(50);
}

void tiro_para::ActualizarVelocidad()
{
    vel_x=vel*cos(ang);
    vel_y=vel*sin(ang)-g*delta;
    ang=atan2(vel_y,vel_x);
    vel= sqrt((vel_x*vel_x) + (vel_y*vel_y));
}
