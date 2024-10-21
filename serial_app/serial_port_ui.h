#ifndef SERIAL_PORT_UI_H
#define SERIAL_PORT_UI_H

#include <QMainWindow>
#include <QWidget>
#include <QSerialPort>
#include <QTextBrowser>

namespace Ui {
class Serial_port_ui;
}

class Serial_port_ui : public QMainWindow
{
    Q_OBJECT

public:
    explicit Serial_port_ui(QWidget *parent = nullptr);
    ~Serial_port_ui();

private slots:
    void on_pushButton_clicked();

    void on_btn_open_serial_clicked();

    void on_to_home_btn_clicked();

    void on_btn_clear_clicked();

    void readbuf();

    void on_btn_close_serial_clicked();

    void on_btn_send_clicked();

private:
    Ui::Serial_port_ui *ui;
    QSerialPort *Serialport;

    void ScanSerialport();
    void InitCombox();


};

#endif // SERIAL_PORT_UI_H
