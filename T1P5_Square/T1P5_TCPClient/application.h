#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include <QApplication>
#include "interface.h"
#include "connector.h"

class TApplication : public QApplication
{
    Q_OBJECT

    TConnector *con;
    TInterface *interface;

public:
    TApplication(int, char**);

public slots:
    void fromConnector(QByteArray);
    void toConnector(QString);
};

#endif // TAPPLICATION_H
