#include "canvas.h"

TCanvas::TCanvas(QWidget* parent) : QWidget(parent) {
    setFixedSize(800, 600);
    timer = new QTimer(this);
    physics = new TPhysics(800, 600, 25, 20, -45);

    connect(timer, &QTimer::timeout, this, &TCanvas::physics_process);
}

TCanvas::~TCanvas() {
    delete timer;
    delete physics;
}

/*
 * Обработка движения шара
 * Вызывается таймером timer
 */
void TCanvas::physics_process() {
    physics->step();
    update();
}

/*
 * Установить новые настройки
 * unsigned l, w - ширина, высота
 * double r - радиус шара
 * double v - начальная скорость
 * double a - угол
 */
void TCanvas::setSettings(unsigned l, unsigned w, double r, double v, double a) {
    setFixedSize(l, w);
    delete physics;
    physics = new TPhysics(l, w, r, v, a);
    update();
}

/*
 * Установить состояние симуляции
 * r = true - запущена
 * r = false - остановлена
 */
void TCanvas::setState(bool r) {
    if (r) {
        timer->start(10);
    } else {
        timer->stop();
        physics->reset();
    }
    running = r;
    update();
}

/*
 * Переключить состояние симуляции
 */
void TCanvas::setState() {
    TCanvas::setState(!running);
}

/*
 * Получить состояние симуляции
 */
bool TCanvas::getState() {
    return running;
}

/*
 * Отрисовка шара
 */
void TCanvas::paintEvent(QPaintEvent*)
{
    QPainter p;
    p.begin(this);

    QSize canvasSize = size();

    QPointF ball = QPointF(physics->getBallX(), physics->getBallY());
    double ballSize = physics->getBallSize();

    // Round box
    p.setPen(QPen(Qt::blue));
    p.drawRect(0, 0, canvasSize.width() - 1, canvasSize.height() - 1);

    // Ball
    p.setPen(QPen(Qt::black));
    p.setBrush(QBrush(Qt::yellow));
    p.drawEllipse(ball, ballSize, ballSize);

    p.end();
}
