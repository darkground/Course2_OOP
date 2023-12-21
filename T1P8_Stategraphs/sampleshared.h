#ifndef SAMPLESHARED_H
#define SAMPLESHARED_H

#include <QPainter>

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

#endif // SAMPLESHARED_H
