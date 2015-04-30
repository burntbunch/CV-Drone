#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QWidget>
#include <CVDrone.h>
#include <QKeyEvent>

namespace Ui {
class ControlWindow;
}

class ControlWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ControlWindow(Drone::CVDrone *cvDrone, QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;
    ~ControlWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::ControlWindow *ui;
    Drone::CVDrone *cvDrone;
    bool flying;

signals:
    void closed();
};

#endif // CONTROLWINDOW_H
