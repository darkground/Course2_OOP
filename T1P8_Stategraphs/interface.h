#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <vector>
#include "matrix.h"
#include "canvas.h"

class TInterface : public QMainWindow
{
    Q_OBJECT

    QLabel* filelabel;
    QLineEdit* filename;
    QPushButton* filechoose;
    QLabel* result;

    TCanvas* canvas = 0;
public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();

    Matrix<qint16>* read(QString&);
    QString check(Matrix<qint16>*);

private slots:
    void openFile();
};
#endif // TINTERFACE_H
