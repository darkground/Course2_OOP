#ifndef TCANVAS_H
#define TCANVAS_H

#include <QWidget>
#include "sample.h"

class TCanvas : public QWidget
{
    Q_OBJECT

    TSample* s;

public:
    TCanvas(TSample*, QWidget *parent = 0);
    ~TCanvas();

protected:
    void paintEvent(QPaintEvent*);
};

#endif // TCANVAS_H
