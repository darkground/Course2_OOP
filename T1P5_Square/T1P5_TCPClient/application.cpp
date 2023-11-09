#include "application.h"

TApplication::TApplication(int argc, char *argv[]) : QApplication(argc,argv) {
    TConnParams pars = { QHostAddress("127.0.0.1"), 10001,
                        QHostAddress("127.0.0.1"), 10000};
    con = new TConnector(pars, this);

    interface = new TInterface();
    interface->show();

    connect(con,SIGNAL(recieved(QByteArray)),this,SLOT(fromConnector(QByteArray)));
    connect(interface,SIGNAL(request(QString)),this,SLOT(toConnector(QString)));
}

void TApplication::fromConnector(QByteArray msg) {
    interface->answer(QString(msg));
}

void TApplication::toConnector(QString msg) {
    con->send(msg.toUtf8());
}
