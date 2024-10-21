#include "serial_port_ui.h"
#include "ui_serial_port_ui.h"

Serial_port_ui::Serial_port_ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Serial_port_ui)
{
    ui->setupUi(this);
}

Serial_port_ui::~Serial_port_ui()
{
    delete ui;
}
