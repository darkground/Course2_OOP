#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class TInterface; }
QT_END_NAMESPACE

class TInterface : public QMainWindow
{
    Q_OBJECT

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();

private slots:
    void apply();
    void state();

private:
    Ui::TInterface *ui;
};
#endif // TINTERFACE_H
