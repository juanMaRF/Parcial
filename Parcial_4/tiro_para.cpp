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
    if(con==0){
        pos_inicial=posy;
        con=1;
    }

    ActualizarVelocidad();


    //Direccion del Ataque especial: (Derecha)
    if(tipo1==1){
        setPosx(getPosx()+vel_x*delta);
    }
    //Direccion del Ataque especial: (Izquierda)
    if(tipo1==0){
        setPosx(getPosx()-vel_x*delta);
    }


    setPosy(getPosy()+vel_y*delta-(0.5*g*delta*delta));
    setPos(getPosx(),getPosy());
}

double tiro_para::getVel_x() const
{
    return vel_x;
}

void tiro_para::setVel_x(double value)
{
    vel_x = value;
}

double tiro_para::getVel_y() const
{
    return vel_y;
}

void tiro_para::setVel_y(double value)
{
    vel_y = value;
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

tiro_para::tiro_para(int x, int y, int tipo, int a)
{
    posx=x;
    posy=y;
    tipo1=tipo;
    ang=a;
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
