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
    o5=new obstaculo(800,300,100,50);scene->addItem(o5);internos.push_back(o5);
    o6=new obstaculo(500,500,100,50);scene->addItem(o6);internos.push_back(o6);

    connect(timepo,SIGNAL(timeout()),this,SLOT(aparicion()));
    timepo->start(500);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::coliciones()
{
    if(!tiros.empty()){
        QList<obstaculo*>::iterator iter=internos.begin();
        for (QList<tiro_para*>::iterator it=tiros.begin();it!=tiros.end();it++) {
            if((*it)->collidesWithItem((*iter))){

            }else{
                iter++;
            }
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    tiroc=new caidaL(550);scene->addItem(tiroc);objetos.push_back(tiroc);
}

void MainWindow::aparicion()
{
    Xt= rand() % 300;
    Yt= rand() % 200;
    tirop=new tiro_para(Xt,Yt,0,45);scene->addItem(tirop);tiros.push_back(tirop);

    Xt= rand() % 400+400;
    Yt= rand() % 200;
    tirop2=new tiro_para(Xt,Yt,0,-45);scene->addItem(tirop2);tiros.push_back(tirop2);
}

