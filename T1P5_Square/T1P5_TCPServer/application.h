#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include <QCoreApplication>
#include "connector.h"
#include "matrixsquare.h"

class TApplication : public QCoreApplication
{
    Q_OBJECT

    TConnector* con;

public:
    TApplication(int argc, char *argv[]);

    MatrixSquare make(QByteArray&);

public slots:

    void recieve(QByteArray);

};

#endif // TAPPLICATION_H
