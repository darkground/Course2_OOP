#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QMainWindow>

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

private:
    Ui::TInterface *ui;
};
#endif // TINTERFACE_H
