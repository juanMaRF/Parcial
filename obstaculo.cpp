#include "obstaculo.h"

int obstaculo::getX() const
{
    return x;
}

void obstaculo::setX(int value)
{
    x = value;
}

int obstaculo::getY() const
{
    return y;
}

void obstaculo::setY(int value)
{
    y = value;
}

int obstaculo::getW() const
{
    return w;
}

void obstaculo::setW(int value)
{
    w = value;
}

int obstaculo::getH() const
{
    return h;
}

void obstaculo::setH(int value)
{
    h = value;
}

obstaculo::obstaculo(int x_, int y_, int w_, int h_)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
}

QRectF obstaculo::boundingRect() const
{
    return QRectF(x,y,w,h);
}

void obstaculo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}
