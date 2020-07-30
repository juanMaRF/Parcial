#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1121,750);
    scene->addRect(scene->sceneRect());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}
