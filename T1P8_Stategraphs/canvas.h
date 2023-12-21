#ifndef TCANVAS_H
#define TCANVAS_H

#include <QWidget>
#include <QMouseEvent>
#include "derivesample.h"

class TCanvas : public QWidget
{
    Q_OBJECT

    TDeriveSample* s;

public:
    TCanvas(TDeriveSample*, QWidget *parent = 0);
    ~TCanvas();

protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
};

#endif // TCANVAS_H
