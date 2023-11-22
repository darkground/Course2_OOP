#include <QDebug>
#include "application.h"
#include "rational.h"
#include "complex.h"

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
    qDebug() << "[info] raw request:" << QString(msg);
    int message_type_pos = msg.indexOf(separator);
    int message_type = msg.left(message_type_pos).toInt();
    msg = msg.right(msg.length() - message_type_pos - 1);
    int mode_pos = msg.indexOf(separator);
    int mode = msg.left(mode_pos).toInt();
    msg = msg.right(msg.length() - mode_pos - 1);
    switch (mode) {
    case MODE_RATIONAL: {
        qDebug() << "[info] type rational";
        MatrixSquare<TRational> m = make<TRational>(msg);
        respond(m, (messages) message_type);
        break;
    }

    case MODE_COMPLEX: {
        qDebug() << "[info] type complex";
        MatrixSquare<TComplex> m = make<TComplex>(msg);
        respond(m, (messages) message_type);
        break;
    }
    case MODE_FLOAT: {
        qDebug() << "[info] type float";
        MatrixSquare<double> m = make<double>(msg);
        respond(m, (messages) message_type);
        break;
    }
    default:
        qDebug() << "[error]: type unknown: " << QString().setNum(message_type);
        break;
    }
}

template <class T>
void TApplication::respond(MatrixSquare<T>& matr, messages msg) {
    QString answer;
    try {
        switch (msg) {
        case REQ_DETERMINANT:
            qDebug() << "[info] determinant requested";
            answer << QString().setNum(ANS_DETERMINANT) << matr.determ() << QString(separator);
            break;
        case REQ_RANK:
            qDebug() << "[info] rank requested";
            answer << QString().setNum(ANS_RANK) << QString().setNum(matr.rank());
            break;
        case REQ_TRANSPOSE:
            qDebug() << "[info] transpose requested";
            matr.transp();
            answer << QString().setNum(ANS_PRINT) << matr << QString(separator);
            break;
        default:
            qDebug() << "[error] unknown request:" << msg;
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
template <class T>
MatrixSquare<T> TApplication::make(QByteArray& msg) {
    T r1,r2,r3,r4,r5,r6,r7,r8,r9;
    msg >> r1 >> r2 >> r3 >> r4 >> r5 >> r6 >> r7 >> r8 >> r9;
    MatrixSquare<T> m = MatrixSquare<T>(3);
    m.init(new T[9] {r1, r2, r3, r4, r5, r6, r7, r8, r9});
    return m;
}
