#ifndef TCANVAS_H
#define TCANVAS_H

#include <QWidget>
#include <QPainter>

class TCanvas : public QWidget
{
public:
    TCanvas(QWidget* parent = 0);
    void resize(unsigned, unsigned);

protected:
    void paintEvent(QPaintEvent*);
};

#endif // TCANVAS_H
