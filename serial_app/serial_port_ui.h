#ifndef SERIAL_PORT_UI_H
#define SERIAL_PORT_UI_H

#include <QMainWindow>

namespace Ui {
class Serial_port_ui;
}

class Serial_port_ui : public QMainWindow
{
    Q_OBJECT

public:
    explicit Serial_port_ui(QWidget *parent = nullptr);
    ~Serial_port_ui();

private:
    Ui::Serial_port_ui *ui;
};

#endif // SERIAL_PORT_UI_H
