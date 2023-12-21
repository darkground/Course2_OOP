#include "sampleshared.h"
#include "sample.h"

TSample::TSample(Matrix<qint16>* mat) {
    matr = mat;
    sides = matr->getSizeX();
}

TSample::~TSample() {
    delete matr;
}

void TSample::draw(QPainter* p, QRect r)
{
    qreal cw = 0.5 * r.width();
    qreal ch = 0.5 * r.height();
    qreal cr = 0.75 * (cw > ch ? ch : cw);
    qreal ps = 20;
    qreal a = 2.0 * acos(-1.0) / sides;

    p->setPen(QPen(Qt::black));
    p->setBrush(QBrush(Qt::black));
    QFont font;
    font.setPointSize(ps);
    font.setBold(true);
    p->setFont(font);

    vector<QPointF> nodes;

    for (unsigned i = 0; i < sides; i++) {
        QPointF qf = QPointF(cw + cr * sin(i * a), ch - cr * cos(i * a));
        nodes.push_back(qf);
    }

    for (unsigned i = 0; i < sides; i++) {
        QPointF qf1 = nodes.at(i);
        for (unsigned j = i + 1; j < sides; j++) {
            QPointF qf2 = nodes.at(j);
            if (matr->get(i, j) != 0)
                drawArrow(p, qf1, offsetAlongLine(qf1, qf2, -ps));
            if (matr->get(j, i) != 0)
                drawArrow(p, qf2, offsetAlongLine(qf2, qf1, -ps));
        }
    }

    p->setBrush(QBrush(Qt::white));
    for (unsigned i = 0; i < sides; i++) {
        QPointF qf1 = nodes.at(i);
        p->drawEllipse(qf1, ps, ps);
        p->drawText(QRectF(qf1.x() - ps, qf1.y() - ps, ps * 2, ps * 2), QString().setNum(i + 1), QTextOption(Qt::AlignCenter));
    }
}


