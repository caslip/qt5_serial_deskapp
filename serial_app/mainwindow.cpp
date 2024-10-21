#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serial_port_ui.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0,0,800,480);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Serial_port_ui* u = new Serial_port_ui();
    u->show();
    this->close();
}
