#include "canvas.h"

TCanvas::TCanvas(QWidget* parent) : QWidget(parent)
{
    setFixedSize(400, 200);
}

void TCanvas::resize(unsigned l, unsigned w) {
    setFixedSize(l, w);
    update();
}

void TCanvas::paintEvent(QPaintEvent*)
{
    QPainter p;
    p.begin(this);
    // demo
    QSize sz = size();

    p.setPen(QPen(Qt::black));
    p.drawRect(0, 0, sz.width() - 1, sz.height() - 1);

    p.setBrush(QBrush(Qt::yellow));
    p.drawEllipse(QPointF(sz.rwidth() / 2, sz.height() / 2), 5, 5);
    //
    p.end();
}
