#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QTimer>
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

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    tiro_para *tirop;
    caidaL *tiroc;
    obstaculo *o,*o1,*o2,*o3,*o4,*o5,*o6,*o7,*o8,*o9;
    QList<obstaculo*> laterales;
    QList<obstaculo*> verticales;
    QList<caidaL*> objetos;
};
#endif // MAINWINDOW_H

