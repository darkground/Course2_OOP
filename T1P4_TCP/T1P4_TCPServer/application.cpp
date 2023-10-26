#include <QDebug>
#include "application.h"
#include "shared.h"

/*
 * Инициализация сервера
 */
TApplication::TApplication(int argc, char *argv[]) : QCoreApplication(argc,argv) {
    TConnParams params = { QHostAddress("127.0.0.1"), 10000, QHostAddress("127.0.0.1"), 10001 };
    con = new TConnector(params, this);

    qDebug() << "[info] server is up";
    connect(con, SIGNAL(recieved(QByteArray)), this, SLOT(recieve(QByteArray)));
}

/*
 * Слот получения данных по TCP
 * QByteArray msg - данные
 */
void TApplication::recieve(QByteArray msg){
    QString answer;
    qDebug() << "[info] raw request:" << QString(msg);
    matrix m = make(msg);
    int pos = msg.indexOf(separator);
    int message_type = msg.left(pos).toInt();
    try {
        switch (message_type) {
        case REQ_DETERMINANT:
            qDebug() << "[info] determinant requested";
            answer << QString().setNum(ANS_DETERMINANT) << (QString) m.determ();
            break;
        case REQ_RANK:
            qDebug() << "[info] rank requested";
            answer << QString().setNum(ANS_RANK) << QString().setNum(m.rank());
            break;
        case REQ_TRANSPOSE:
            qDebug() << "[info] transpose requested";
            m.transp();
            answer << QString().setNum(ANS_PRINT) << m << QString(separator);
            break;
        default:
            qDebug() << "[error] unknown request:" << message_type;
            return;
        }
    } catch (std::runtime_error e) {
        answer = QString();
        qDebug() << "[error] runtime error:" << e.what();
        answer << QString().setNum(ANS_ERROR) << e.what();
    }
    qDebug() << "[info] raw response:" << answer;
    con->send(answer.toUtf8());
}

/*
 * Собрать матрицу из данных QByteArray
 * QByteArray& msg - данные
 */
matrix TApplication::make(QByteArray& msg) {
    TRational r1,r2,r3,r4,r5,r6,r7,r8,r9;
    msg >> r1 >> r2 >> r3 >> r4 >> r5 >> r6 >> r7 >> r8 >> r9;
    matrix m = matrix(3);
    m.init(new number[9] {r1, r2, r3, r4, r5, r6, r7, r8, r9}, 3);
    return m;
}
