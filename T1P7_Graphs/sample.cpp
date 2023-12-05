#include "sample.h"
#include <QDebug>

TSample::TSample(Matrix<qint16>* mat) {
    matr = mat;
    sides = matr->getSizeX();
}

TSample::~TSample() {
    delete matr;
}

QPointF offsetAlongLine(const QPointF& start, const QPointF& end, qreal distance) {
    // Calculate the direction vector of the line
    QPointF direction = end - start;

    // Normalize the direction vector
    qreal length = QLineF(start, end).length();
    direction /= length;

    // Offset the point along the direction vector
    return end + direction * distance;
}

// Function to calculate the angle between two points
qreal angle(const QPointF &p1, const QPointF &p2) {
    return qAtan2(p2.y() - p1.y(), p2.x() - p1.x()) * 180.0 / M_PI;
}

// Function to rotate a point around another point
QPointF rotatePoint(const QPointF &point, qreal angle) {
    qreal radianAngle = angle * M_PI / 180.0;
    qreal x = point.x() * qCos(radianAngle) - point.y() * qSin(radianAngle);
    qreal y = point.x() * qSin(radianAngle) + point.y() * qCos(radianAngle);
    return QPointF(x, y);
}

void drawArrow(QPainter* p, QPointF qf1, QPointF qf2) {
    p->drawLine(qf1, qf2);

    // Calculate the arrowhead points
    QPointF arrowPoints[3] = {
        qf2,  // Arrow tip (end point)
        qf2 + rotatePoint(QPointF(-10, -5), angle(qf1, qf2)),  // Arrowhead point 1
        qf2 + rotatePoint(QPointF(-10, 5), angle(qf1, qf2))    // Arrowhead point 2
    };

    // Draw the arrowhead
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


