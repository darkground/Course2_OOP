#ifndef TCANVAS_H
#define TCANVAS_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "physics.h"

class TCanvas : public QWidget
{
public:
    TCanvas(QWidget* parent = 0);
    ~TCanvas();
    void setSettings(unsigned l, unsigned w, double r = 25., double v = 20., double a = 45.);
    void setState(bool r);
    void setState();
    bool getState();

private:
    void paintEvent(QPaintEvent*);

    TPhysics *physics;
    QTimer *timer;
    bool running = false;

private slots:
    void physics_process();
};

#endif // TCANVAS_H
