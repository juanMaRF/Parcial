#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1111,740);
    scene->addRect(scene->sceneRect());


    o=new obstaculo(-5,-5,1500,5);scene->addItem(o);
    o1=new obstaculo(-5,740,1500,5);scene->addItem(o1);
    o2=new obstaculo(-5,-5,5,1500);scene->addItem(o2);
    o3=new obstaculo(1110,-5,5,1500);scene->addItem(o3);
    o4=new obstaculo(200,300,100,50);scene->addItem(o4);
    o5=new obstaculo(800,300,100,50);scene->addItem(o5);
    o6=new obstaculo(500,500,100,50);scene->addItem(o6);
    o7=new obstaculo(200,600,100,50);scene->addItem(o7);
    o8=new obstaculo(800,600,100,50);scene->addItem(o8);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}
