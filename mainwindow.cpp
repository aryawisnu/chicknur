#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->turnON, SIGNAL(clicked()), this, SLOT(turnONlamp()));
    QObject::connect(ui->turnOFF, SIGNAL(clicked()), this, SLOT(turnOFFlamp()));
    QObject::connect(ui->sendData, SIGNAL(clicked()), this, SLOT(sendData()));
    QObject::connect(ui->autoButton, SIGNAL(clicked()), this, SLOT(modeAuto()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::turnONlamp()
{
   QProcess *process = new QProcess();
   QString path = "/home/aryawisnu/ChickNur";
   QString  command("/usr/bin/python2.7");
   QStringList params = QStringList() << "/home/aryawisnu/ChickNur/tuya.py --lampu 1 --warna 255,255,255 --cerah 100";
   process->startDetached("/usr/bin/python2.7 /home/aryawisnu/ChickNur/tuya.py --lampu 1 --warna 255,255,255 --cerah 100");
   process->waitForFinished();
   process->close();
}

void MainWindow::turnOFFlamp()
{
    QProcess *process = new QProcess();
    QString path = "/home/aryawisnu/ChickNur";
    QString  command("/usr/bin/python2.7");
    QStringList params = QStringList() << "/home/aryawisnu/ChickNur/tuya.py --lampu 1 --warna 255,255,255 --cerah 100";
    process->startDetached("/usr/bin/python2.7 /home/aryawisnu/ChickNur/tuya.py --lampu 0 --warna 255,255,255 --cerah 100");
    process->waitForFinished();
    process->close();
}

void MainWindow::sendData()
{
    brightness = ui->brightnessSLider->value();
    redValue = ui->redSlider->value();
    greenValue = ui->greenSlider->value();
    blueValue = ui->blueSlider->value();

    QProcess *process = new QProcess();
    QString command = "/usr/bin/python2.7 /home/aryawisnu/ChickNur/tuya.py --lampu 1 --warna " + QString::number(redValue) + "," + QString::number(greenValue) + "," + QString::number(blueValue) + " --cerah " + QString::number(brightness);
    process->startDetached(command);
    process->waitForFinished();
    process->close();
}

void MainWindow::modeAuto()
{
    QString hari = ui->inputHari->text();
    int jumlahHari = hari.toInt();
    ui->nilaiHari->display(hari);
    if(jumlahHari <= 3){
        ui->masaTumbuh->clear();
        ui->nilaiBrightness->clear();
        ui->masaTumbuh->append("Brooding");
        ui->nilaiBrightness->append("100");
    }
    else if(jumlahHari > 3 && jumlahHari <= 10){
        ui->masaTumbuh->clear();
        ui->nilaiBrightness->clear();
        ui->nilaiJamgelap->clear();
        ui->masaTumbuh->append("Groowing");
        ui->nilaiBrightness->append("100");
        ui->nilaiJamgelap->append("1 Jam");
    }
    else if(jumlahHari > 10 && jumlahHari <= 21){
        ui->masaTumbuh->clear();
        ui->nilaiBrightness->clear();
        ui->nilaiJamgelap->clear();
        ui->masaTumbuh->append("Groowing");
        ui->nilaiBrightness->append("25");
        ui->nilaiJamgelap->append("4 Jam");
    }
    else{
        ui->masaTumbuh->clear();
        ui->nilaiBrightness->clear();
        ui->nilaiJamgelap->clear();
        ui->masaTumbuh->append("Groowing");
        ui->nilaiBrightness->append("25");
        ui->nilaiJamgelap->append("1 Jam");
    }
}
