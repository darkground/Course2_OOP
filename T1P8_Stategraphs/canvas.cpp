#include "canvas.h"

TCanvas::TCanvas(TDeriveSample* f, QWidget *parent) : QWidget(parent)
{
    s = f;
    setFixedSize(400,400);
    setWindowTitle("Graph Viewer");
}

TCanvas::~TCanvas()
{
    delete s;
}

/*
 * QPainter событие paintEvent
 */
void TCanvas::paintEvent(QPaintEvent*)
{
    QPainter p;
    p.begin(this);
    s->draw(&p, rect());
    p.end();
}

void TCanvas::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)  s->newEvent(false);
    if (event->button() == Qt::RightButton) s->newEvent(true);
    update();
}
