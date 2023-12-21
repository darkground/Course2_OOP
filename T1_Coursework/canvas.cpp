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

void TCanvas::physics_process() {
    physics->step();
    update();
}

void TCanvas::setSettings(unsigned l, unsigned w, double r, double v, double a) {
    setFixedSize(l, w);
    delete physics;
    physics = new TPhysics(l, w, r, v, a);
    update();
}

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

void TCanvas::setState() {
    TCanvas::setState(!running);
}

bool TCanvas::getState() {
    return running;
}

void TCanvas::paintEvent(QPaintEvent*)
{
    QPainter p;
    p.begin(this);

    QSize canvasSize = size();

    QPointF ball = QPointF(physics->getBallX(), physics->getBallY());
    double ballSize = physics->getBallSize();

    p.setPen(QPen(Qt::blue));
    p.drawRect(0, 0, canvasSize.width() - 1, canvasSize.height() - 1);

    p.setPen(QPen(Qt::black));
    p.setBrush(QBrush(Qt::yellow));
    p.drawEllipse(ball, ballSize, ballSize);

    p.end();
}
