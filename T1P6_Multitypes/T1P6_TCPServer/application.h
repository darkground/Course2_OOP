#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include <QCoreApplication>
#include "connector.h"
#include "matrixsquare.h"
#include "shared.h"

class TApplication : public QCoreApplication
{
    Q_OBJECT

    TConnector* con;

public:
    TApplication(int argc, char *argv[]);

    template <class T> MatrixSquare<T> make(QByteArray&);
    template <class T> void respond(MatrixSquare<T>&, messages);

public slots:

    void recieve(QByteArray);

};

#endif // TAPPLICATION_H
