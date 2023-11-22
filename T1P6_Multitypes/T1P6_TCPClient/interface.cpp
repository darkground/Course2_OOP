#include "interface.h"
#include "shared.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("OOP Practice #6 [Client]");
    setFixedSize(460, 275);
    // Интерфейс матрицы
    n1 = new QLabel("M[1,1] = ", this);
    n1->setGeometry(20, 20, 50, 25);
    n1_sep = new QLabel("/", this);
    n1_sep->setGeometry(80, 35, 30, 20);
    n1_first = new QLineEdit("1", this);
    n1_first->setGeometry(70, 15, 30, 20);
    n1_second = new QLineEdit("1", this);
    n1_second->setGeometry(90, 35, 30, 20);
    //
    n2 = new QLabel("M[1,2] = ", this);
    n2->setGeometry(130, 20, 50, 25);
    n2_sep = new QLabel("/", this);
    n2_sep->setGeometry(190, 35, 30, 20);
    n2_first = new QLineEdit("1", this);
    n2_first->setGeometry(180, 15, 30, 20);
    n2_second = new QLineEdit("1", this);
    n2_second->setGeometry(200, 35, 30, 20);
    //
    n3 = new QLabel("M[1,3] = ", this);
    n3->setGeometry(240, 20, 50, 25);
    n3_sep = new QLabel("/", this);
    n3_sep->setGeometry(300, 35, 30, 20);
    n3_first = new QLineEdit("1", this);
    n3_first->setGeometry(290, 15, 30, 20);
    n3_second = new QLineEdit("1", this);
    n3_second->setGeometry(310, 35, 30, 20);
    //
    n4 = new QLabel("M[2,1] = ", this);
    n4->setGeometry(20, 80, 50, 25);
    n4_sep = new QLabel("/", this);
    n4_sep->setGeometry(80, 95, 30, 20);
    n4_first = new QLineEdit("1", this);
    n4_first->setGeometry(70, 75, 30, 20);
    n4_second = new QLineEdit("1", this);
    n4_second->setGeometry(90, 95, 30, 20);
    //
    n5 = new QLabel("M[2,2] = ", this);
    n5->setGeometry(130, 80, 50, 25);
    n5_sep = new QLabel("/", this);
    n5_sep->setGeometry(190, 95, 30, 20);
    n5_first = new QLineEdit("1", this);
    n5_first->setGeometry(180, 75, 30, 20);
    n5_second = new QLineEdit("1", this);
    n5_second->setGeometry(200, 95, 30, 20);
    //
    n6 = new QLabel("M[2,3] = ", this);
    n6->setGeometry(240, 80, 50, 25);
    n6_sep = new QLabel("/", this);
    n6_sep->setGeometry(300, 95, 30, 20);
    n6_first = new QLineEdit("1", this);
    n6_first->setGeometry(290, 75, 30, 20);
    n6_second = new QLineEdit("1", this);
    n6_second->setGeometry(310, 95, 30, 20);
    //
    n7 = new QLabel("M[3,1] = ", this);
    n7->setGeometry(20, 140, 50, 25);
    n7_sep = new QLabel("/", this);
    n7_sep->setGeometry(80, 155, 30, 20);
    n7_first = new QLineEdit("1", this);
    n7_first->setGeometry(70, 135, 30, 20);
    n7_second = new QLineEdit("1", this);
    n7_second->setGeometry(90, 155, 30, 20);
    //
    n8 = new QLabel("M[3,2] = ", this);
    n8->setGeometry(130, 140, 50, 25);
    n8_sep = new QLabel("/", this);
    n8_sep->setGeometry(190, 155, 30, 20);
    n8_first = new QLineEdit("1", this);
    n8_first->setGeometry(180, 135, 30, 20);
    n8_second = new QLineEdit("1", this);
    n8_second->setGeometry(200, 155, 30, 20);
    //
    n9 = new QLabel("M[3,3] = ", this);
    n9->setGeometry(240, 140, 50, 25);
    n9_sep = new QLabel("/", this);
    n9_sep->setGeometry(300, 155, 30, 20);
    n9_first = new QLineEdit("1", this);
    n9_first->setGeometry(290, 135, 30, 20);
    n9_second = new QLineEdit("1", this);
    n9_second->setGeometry(310, 155, 30, 20);
    // Кнопки управления
    b_determ = new QPushButton("Determinant", this);
    b_determ->setGeometry(360, 20, 80, 30);
    b_rank = new QPushButton("Rank", this);
    b_rank->setGeometry(360, 50, 80, 30);
    b_transp = new QPushButton("Transpose", this);
    b_transp->setGeometry(360, 80, 80, 30);
    // Текст с результатом
    op_result = new QLabel("Operate on the matrix using buttons and text fields above...", this);
    op_result->setGeometry(40, 190, 320, 80);
    // Смена типов
    r_rational = new QRadioButton("Rational", this);
    r_rational->setGeometry(360, 110, 80, 30);
    r_complex = new QRadioButton("Complex", this);
    r_complex->setGeometry(360, 130, 80, 30);
    r_float = new QRadioButton("Float", this);
    r_float->setGeometry(360, 150, 80, 30);
    r_rational->setChecked(true);
    // Соединение сигналов и слотов
    connect(b_determ, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(b_rank, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(b_transp, SIGNAL(pressed()), this, SLOT(formRequest()));
}

TInterface::~TInterface()
{
    delete n1;
    delete n1_first;
    delete n1_second;
    delete n1_sep;
    delete n2;
    delete n2_first;
    delete n2_second;
    delete n2_sep;
    delete n3;
    delete n3_first;
    delete n3_second;
    delete n3_sep;
    delete n4;
    delete n4_first;
    delete n4_second;
    delete n4_sep;
    delete n5;
    delete n5_first;
    delete n5_second;
    delete n5_sep;
    delete n6;
    delete n6_first;
    delete n6_second;
    delete n6_sep;
    delete n7;
    delete n7_first;
    delete n7_second;
    delete n7_sep;
    delete n8;
    delete n8_first;
    delete n8_second;
    delete n8_sep;
    delete n9;
    delete n9_first;
    delete n9_second;
    delete n9_sep;

    delete b_determ;
    delete b_rank;
    delete b_transp;

    delete r_rational;
    delete r_complex;
    delete r_float;

    delete op_result;
}

/*
 * Создание запроса серверу
 */
void TInterface::formRequest() {
    QString msg;
    msg << n1_first->text() << n1_second->text();
    msg << n2_first->text() << n2_second->text();
    msg << n3_first->text() << n3_second->text();
    msg << n4_first->text() << n4_second->text();
    msg << n5_first->text() << n5_second->text();
    msg << n6_first->text() << n6_second->text();
    msg << n7_first->text() << n7_second->text();
    msg << n8_first->text() << n8_second->text();
    msg << n9_first->text() << n9_second->text();
    QPushButton *btn = (QPushButton*)sender(); // Определение кнопки отправителя
    if (btn == b_determ) {
        msg << QString().setNum(REQ_DETERMINANT);
    } else if (btn == b_rank) {
        msg << QString().setNum(REQ_RANK);
    } else if (btn == b_transp) {
        msg << QString().setNum(REQ_TRANSPOSE);
    }
    emit request(msg);
}

/*
 * Получение запроса от сервера
 */
void TInterface::answer(QString msg)
{
    QString text;
    int p = msg.indexOf(separator);
    int message_type = msg.left(p).toInt();
    msg = msg.mid(p+1,msg.length()-p-2);
    switch (message_type)
    {
    case ANS_DETERMINANT:
        text = "Determinant: " + msg;
        break;
    case ANS_ERROR:
        text = "Error: " + msg;
        break;
    case ANS_PRINT:
        text = "Matrix: " + msg;
        break;
    case ANS_RANK:
        text = "Rank: " + msg;
        break;
    default:
        // Сервер недоступен или код неверный
        text = "Server is unreachable or provided invalid code (" + QString().setNum(message_type) + ")";
        break;
    }
    op_result->setText(text);
}
