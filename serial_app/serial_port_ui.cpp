#include "serial_port_ui.h"
#include "ui_serial_port_ui.h"
#include "mainwindow.h"
#include <QSerialPortInfo>
#include <QComboBox>
#include <QList>
#include <QString>
#include <QByteArray>
#include <QTextBrowser>
#include <QTextEdit>
#include <QDebug>

Serial_port_ui::Serial_port_ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Serial_port_ui)
{
    ui->setupUi(this);
    this->setGeometry(0,0,800,480);
    Serialport = new QSerialPort(this);

    ScanSerialport();
    InitCombox();

    ui->receive_text->setPlaceholderText("接收到的消息");
    ui->textEdit->setText("Hello");

    connect(Serialport,SIGNAL(readyRead()),this,SLOT(readbuf()));
}

void Serial_port_ui::ScanSerialport(){
    //QSerialPortInfo类中，使用availablePorts函数可以查看当前所有可用串口，返回值类型为const QSerialPortInfo
    foreach (const QSerialPortInfo info, QSerialPortInfo::availablePorts()) {
        ui->comboBox_port->addItem(info.portName());        //调用addItem方法添加到下拉框中
    }
}

Serial_port_ui::~Serial_port_ui()
{
    delete ui;
}

void Serial_port_ui::on_pushButton_clicked()
{
    MainWindow *m = new MainWindow();
    m->show();
    this->close();
}

void Serial_port_ui::InitCombox(){

    ui->comboBox_stopbit->setCurrentIndex(0);
    ui->comboBox_boadrate->setCurrentIndex(7);
    ui->comboBox_databit->setCurrentIndex(3);
    ui->comboBox_parity->setCurrentIndex(0);

}
void Serial_port_ui::on_btn_open_serial_clicked()
{
    Serialport->setBaudRate(ui->comboBox_boadrate->currentText().toInt());
    Serialport->setPortName(ui->comboBox_port->currentText());
    //设置数据位
    switch (ui->comboBox_databit->currentText().toInt()) {
    case 5:
        Serialport->setDataBits(QSerialPort::Data5);
        break;
    case 6:
        Serialport->setDataBits(QSerialPort::Data6);
        break;
    case 7:
        Serialport->setDataBits(QSerialPort::Data7);
        break;
    case 8:
        Serialport->setDataBits(QSerialPort::Data8);
        break;
    default: break;
    }
    /* 设置奇偶校验 */
    switch (ui->comboBox_parity->currentIndex()) {
    case 0:
        Serialport->setParity(QSerialPort::NoParity);
        break;
    case 1:
        Serialport->setParity(QSerialPort::OddParity);
        break;
    case 2:
        Serialport->setParity(QSerialPort::EvenParity);
        break;
    default: break;
    }
    /* 设置停止位 */
    switch (ui->comboBox_stopbit->currentText().toInt()) {
    case 1:
        Serialport->setStopBits(QSerialPort::OneStop);
        break;
    case 2:
        Serialport->setStopBits(QSerialPort::TwoStop);
        break;
    default: break;
    }

    ui->btn_open_serial->setEnabled(false);
    ui->comboBox_boadrate->setEnabled(false);
    ui->comboBox_databit->setEnabled(false);
    ui->comboBox_parity->setEnabled(false);
    ui->comboBox_port->setEnabled(false);
    ui->comboBox_stopbit->setEnabled(false);

    ui->btn_close_serial->setEnabled(true);

    Serialport->open(QIODevice::ReadWrite);//开启串口

}

void Serial_port_ui::readbuf(){
    QByteArray buf = Serialport->readAll();
    ui->receive_text->insertPlainText(QString(buf));
}

void Serial_port_ui::on_to_home_btn_clicked()
{
    MainWindow *m = new MainWindow();
    m->show();
    this->close();
}

void Serial_port_ui::on_btn_clear_clicked()
{
    ui->receive_text->clear();
}

//关闭串口
void Serial_port_ui::on_btn_close_serial_clicked()
{
    Serialport->close();

    ui->btn_open_serial->setEnabled(true);
    ui->comboBox_boadrate->setEnabled(true);
    ui->comboBox_databit->setEnabled(true);
    ui->comboBox_parity->setEnabled(true);
    ui->comboBox_port->setEnabled(true);
    ui->comboBox_stopbit->setEnabled(true);

    ui->btn_close_serial->setEnabled(false);
}

void Serial_port_ui::on_btn_send_clicked()
{
    QByteArray data = ui->textEdit->toPlainText().toUtf8();
    Serialport->write(data);
}
