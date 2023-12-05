#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <matrix.h>
#include <vector>

class TInterface : public QMainWindow
{
    Q_OBJECT

    QLabel* filelabel;
    QLineEdit* filename;
    QPushButton* filechoose;

    QLabel* result;
    QPushButton* go;
public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();

    Matrix<qint16>* read(QString&);
    bool isValid(Matrix<qint16>*);

private slots:
    void openFile();
};
#endif // TINTERFACE_H
