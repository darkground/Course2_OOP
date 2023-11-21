#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>

struct TConnParams
{
    QHostAddress rHost;
    quint16      rPort;
    QHostAddress sHost;
    quint16      sPort;
};

class TConnector : public QUdpSocket
{
    Q_OBJECT

    bool         ready;
    TConnParams  params;

public:
    TConnector(TConnParams&,QObject *parent = nullptr);
    bool isReady();

signals:
    void recieved(QByteArray);

public slots:
    void send(QByteArray);

private slots:
    void recieve();

};

#endif // CONNECTOR_H
