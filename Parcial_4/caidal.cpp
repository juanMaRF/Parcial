#include "caidal.h"
#include "obstaculo.h"
#include <QGraphicsScene>

caidaL::caidaL(int x,QGraphicsItem * parent): QObject()
{
    PosX= x;
    PosY=70;
    Vel=0;
    w=10;
    h=10;

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);

}

void caidaL::actu_vel()
{
    Vel=Vel-g*delta;
}

QRectF caidaL::boundingRect() const
{
    return QRectF(-r,-r,r*2,r*2);
}

void caidaL::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void caidaL::move()
{

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid (obstaculo) || PosX<=0 || PosX>=900 || PosY<=0){
            Vel*=-1;
            r-=1;
        }
        if(PosY>=600){
            scene()->removeItem(this);
            delete this;
        }
        if(r==0){
            scene()->removeItem(this);
        }
    }

    if(con==0){
        pos_inicial=PosY;
        con=2;
    }

    PosY=PosY-(0.5*Vel*delta);
    setPos(PosX,PosY);
    actu_vel();
}
