#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void turnONlamp();
    void turnOFFlamp();
    void sendData();
    void modeAuto();

private:
    Ui::MainWindow *ui;
    int brightness;
    int redValue;
    int greenValue;
    int blueValue;
};
#endif // MAINWINDOW_H
