#include "derivesample.h"

TDeriveSample::TDeriveSample(Matrix<qint16>* m) : TSample(m)
{
    active = 0;
}

void TDeriveSample::draw(QPainter* p, QRect r)
{
    TSample::draw(p, r);
    qreal cw = 0.5 * r.width();
    qreal ch = 0.5 * r.height();
    qreal cr = 0.75 * (cw > ch ? ch : cw);
    qreal ps = 20;
    qreal a = 2.0 * acos(-1.0) / sides;

    p->setPen(QPen(Qt::black));
    p->setBrush(QBrush(Qt::yellow));
    QFont font;
    font.setPointSize(ps);
    font.setBold(true);
    p->setFont(font);

    QPointF qf = QPointF(cw + cr * sin(active * a), ch - cr * cos(active * a));
    p->drawEllipse(qf, ps, ps);
    p->drawText(QRectF(qf.x() - ps, qf.y() - ps, ps * 2, ps * 2), QString().setNum(active + 1), QTextOption(Qt::AlignCenter));
}

void TDeriveSample::newEvent(bool direction)
{
    if (direction) active++;
    else active = --active + sides;
    active = active % sides;
}
