#include <QDebug>
#include "application.h"
#include "shared.h"

TApplication::TApplication(int argc, char *argv[]) : QCoreApplication(argc,argv) {
    TConnParams params = { QHostAddress("127.0.0.1"), 10000, QHostAddress("127.0.0.1"), 10001 };
    con = new TConnector(params, this);

    qDebug() << "[info] server is up";
    connect(con, SIGNAL(recieved(QByteArray)), this, SLOT(recieve(QByteArray)));
}

void TApplication::recieve(QByteArray msg){
    QString answer;
    matrix m = make(msg);
    int pos = msg.indexOf(separator);
    int message_type = msg.left(pos).toInt();
    try {
        switch (message_type) {
        case REQ_DETERMINANT:
            qDebug() << "[info] determinant request";
            answer << QString().setNum(ANS_DETERMINANT) << (QString) m.determ();
            break;
        case REQ_RANK:
            qDebug() << "[info] rank request";
            answer << QString().setNum(ANS_RANK) << QString().setNum(m.rank());
            break;
        case REQ_TRANSPOSE:
            qDebug() << "[info] transpose request";
            answer << QString().setNum(ANS_PRINT) << m;
            break;
        default:
            qDebug() << "[info] unknown request: " << message_type;
            return;
        }
    } catch (std::runtime_error e) {
        qDebug() << "[error] runtime error: " << e.what();
        answer << QString().setNum(ANS_ERROR) << e.what();
    }
    con->send(answer.toUtf8());
}

/*
 * Собрать матрицу из элементов QByteArray
 */
matrix TApplication::make(QByteArray& msg) {
    TRational r1,r2,r3,r4,r5,r6,r7,r8,r9;
    msg >> r1 >> r2 >> r3 >> r4 >> r5 >> r6 >> r7 >> r8 >> r9;
    matrix m = matrix(3);
    m.init(new number[9] {r1, r2, r3, r4, r5, r6, r7, r8, r9}, 3);
    return m;
}
