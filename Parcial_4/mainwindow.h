#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QTimer>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
#include "caidal.h"
#include "tiro_para.h"
#include "obstaculo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void coliciones();

private slots:
    void on_pushButton_clicked();
    void aparicion();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    tiro_para *tirop,*tirop2;
    caidaL *tiroc;
    obstaculo *o,*o1,*o2,*o3,*o4,*o5,*o6,*o7,*o8,*o9;
    QList<obstaculo*> laterales;
    QList<obstaculo*> verticales;
    QList<obstaculo*> internos;
    QList<caidaL*> objetos;
    QList<tiro_para*> tiros;
    QTimer *timepo=new QTimer,*timepo2=new QTimer;
    int Xt,Yt;
};
#endif // MAINWINDOW_H

