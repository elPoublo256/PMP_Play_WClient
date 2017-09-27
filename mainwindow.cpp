#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    connect(ui->pushButton, SIGNAL(clicked(bool)),this, SLOT(RunClient()));
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RunClient()
{
    //MyClient* cl=new MyClient(ui->LE_HostName->text(), ui->LE_Port->text().toInt());
    //cl->show();
}
