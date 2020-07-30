#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class obstaculo: public QGraphicsItem,public QObject
{
    int x;
    int y;
    int w;
    int h;
public:
    obstaculo();
    obstaculo(int x_, int y_, int w_, int h_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int getW() const;
    void setW(int value);
    int getH() const;
    void setH(int value);
};

#endif // OBSTACULO_H
