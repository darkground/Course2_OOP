#include "interface.h"
#include "ui_interface.h"
#include <QDebug>

TInterface::TInterface(QWidget *parent) : QMainWindow(parent), ui(new Ui::TInterface)
{
    ui->setupUi(this);

    connect(ui->applyBtn, SIGNAL(clicked()), this, SLOT(apply()));
    connect(ui->stateBtn, SIGNAL(clicked()), this, SLOT(state()));
}

TInterface::~TInterface()
{
    delete ui;
}


/*
 * Применить настройки интерфейса
 * unsigned l, w - ширина, высота (>= 32)
 * double r - радиус (< ширина или высота / 2)
 * double v - начальная скорость
 * double a - начальный угол
 */
void TInterface::apply()
{
    bool ok_l = false;
    unsigned l = ui->lEdit->text().toInt(&ok_l);
    bool ok_w = false;
    unsigned w = ui->wEdit->text().toInt(&ok_w);
    bool ok_r = false;
    double r = ui->rEdit->text().toDouble(&ok_r);
    bool ok_v = false;
    double v = ui->vEdit->text().toDouble(&ok_v);
    bool ok_a = false;
    double a = -ui->aEdit->text().toDouble(&ok_a);

    if (!ok_l || !ok_w || l < 32 || w < 32) return;
    if (!ok_r || r >= l / 2 || r >= w / 2) return;
    if (!ok_v || !ok_a) return;

    ui->canvas->setSettings(l, w, r, v, a);
}

/*
 * Установка состояния симуляции
 * Если она запущена, то она остановится, и наоборот
 */
void TInterface::state(){
    ui->canvas->setState();
    if (ui->canvas->getState()) {
        // Simulation enabled
        ui->stateBtn->setText("Stop");
        ui->applyBtn->setEnabled(false);
    } else {
        // Simulation disabled
        ui->stateBtn->setText("Start");
        ui->applyBtn->setEnabled(true);
    }
}
