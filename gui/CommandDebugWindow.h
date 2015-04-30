#ifndef COMMANDDEBUGWINDOW_H
#define COMMANDDEBUGWINDOW_H

#include <QWidget>
#include <CommandService.h>

namespace Ui {
class CommandDebugWindow;
}

class CommandDebugWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CommandDebugWindow(Drone::CommandService *service, QWidget *parent = 0);
    ~CommandDebugWindow();


protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::CommandDebugWindow *ui;
    Drone::CommandService *service;

signals:
    void closed();

private slots:
    void commandDebugMessageReceived(QString message);
};

#endif // COMMANDDEBUGWINDOW_H
