#include "sample.h"

TSample::TSample(Matrix<qint16>* mat) {
    matr = mat;
    sides = matr->getSizeX();
}

TSample::~TSample() {
    delete matr;
}

/*
 * Смещение точки end на определённую дистанцию distance вдоль линии, созданной точками start и end
 */
QPointF offsetAlongLine(const QPointF& p1, const QPointF& p2, qreal distance) {
    QPointF direction = p2 - p1;

    qreal length = QLineF(p1, p2).length();
    direction /= length;

    return p2 + direction * distance;
}

/*
 * Угол между двумя точками p1 и p2
 */
qreal angle(const QPointF& p1, const QPointF& p2) {
    return qAtan2(p2.y() - p1.y(), p2.x() - p1.x()) * 180.0 / M_PI;
}

/*
 * Вращение определённой точки point на градус angle
 */
QPointF rotatePoint(const QPointF& p1, qreal angle) {
    qreal radianAngle = angle * M_PI / 180.0;
    qreal x = p1.x() * qCos(radianAngle) - p1.y() * qSin(radianAngle);
    qreal y = p1.x() * qSin(radianAngle) + p1.y() * qCos(radianAngle);
    return QPointF(x, y);
}

/*
 * Нарисовать стрелку используя QPainter p от точки p1 до точки p2
 */
void drawArrow(QPainter* p, QPointF p1, QPointF p2) {
    p->drawLine(p1, p2);

    QPointF arrowPoints[3] = {
        p2,
        p2 + rotatePoint(QPointF(-10, -5), angle(p1, p2)),
        p2 + rotatePoint(QPointF(-10, 5), angle(p1, p2))
    };

    p->drawPolygon(arrowPoints, 3);
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


