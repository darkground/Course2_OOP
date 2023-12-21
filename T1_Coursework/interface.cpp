#include "interface.h"
#include "ui_interface.h"
#include <QDebug>

TInterface::TInterface(QWidget *parent) : QMainWindow(parent), ui(new Ui::TInterface)
{
    ui->setupUi(this);

    connect(ui->applyBtn, SIGNAL(clicked()), this, SLOT(apply()));
}

TInterface::~TInterface()
{
    delete ui;
}


void TInterface::apply()
{
    ui->canvas->resize(
        ui->lEdit->text().toInt(),
        ui->wEdit->text().toInt()
        );
}

