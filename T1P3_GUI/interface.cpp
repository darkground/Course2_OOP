#include "interface.h"
#include "rational.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("OOP Practice #3");
    setFixedSize(400, 270);
    // Интерфейс матрицы
    n1 = new QLabel("M[1,1] = ", this);
    n1->setGeometry(20, 20, 50, 25);
    n1_num = new QLineEdit("1", this);
    n1_num->setGeometry(70, 15, 30, 20);
    n1_deno = new QLineEdit("1", this);
    n1_deno->setGeometry(70, 35, 30, 20);
    //
    n2 = new QLabel("M[1,2] = ", this);
    n2->setGeometry(110, 20, 50, 25);
    n2_num = new QLineEdit("1", this);
    n2_num->setGeometry(160, 15, 30, 20);
    n2_deno = new QLineEdit("1", this);
    n2_deno->setGeometry(160, 35, 30, 20);
    //
    n3 = new QLabel("M[1,3] = ", this);
    n3->setGeometry(200, 20, 50, 25);
    n3_num = new QLineEdit("1", this);
    n3_num->setGeometry(250, 15, 30, 20);
    n3_deno = new QLineEdit("1", this);
    n3_deno->setGeometry(250, 35, 30, 20);
    //
    n4 = new QLabel("M[2,1] = ", this);
    n4->setGeometry(20, 80, 50, 25);
    n4_num = new QLineEdit("1", this);
    n4_num->setGeometry(70, 75, 30, 20);
    n4_deno = new QLineEdit("1", this);
    n4_deno->setGeometry(70, 95, 30, 20);
    //
    n5 = new QLabel("M[2,2] = ", this);
    n5->setGeometry(110, 80, 50, 25);
    n5_num = new QLineEdit("1", this);
    n5_num->setGeometry(160, 75, 30, 20);
    n5_deno = new QLineEdit("1", this);
    n5_deno->setGeometry(160, 95, 30, 20);
    //
    n6 = new QLabel("M[2,3] = ", this);
    n6->setGeometry(200, 80, 50, 25);
    n6_num = new QLineEdit("1", this);
    n6_num->setGeometry(250, 75, 30, 20);
    n6_deno = new QLineEdit("1", this);
    n6_deno->setGeometry(250, 95, 30, 20);
    //
    n7 = new QLabel("M[3,1] = ", this);
    n7->setGeometry(20, 140, 50, 25);
    n7_num = new QLineEdit("1", this);
    n7_num->setGeometry(70, 135, 30, 20);
    n7_deno = new QLineEdit("1", this);
    n7_deno->setGeometry(70, 155, 30, 20);
    //
    n8 = new QLabel("M[3,2] = ", this);
    n8->setGeometry(110, 140, 50, 25);
    n8_num = new QLineEdit("1", this);
    n8_num->setGeometry(160, 135, 30, 20);
    n8_deno = new QLineEdit("1", this);
    n8_deno->setGeometry(160, 155, 30, 20);
    //
    n9 = new QLabel("M[3,3] = ", this);
    n9->setGeometry(200, 140, 50, 25);
    n9_num = new QLineEdit("1", this);
    n9_num->setGeometry(250, 135, 30, 20);
    n9_deno = new QLineEdit("1", this);
    n9_deno->setGeometry(250, 155, 30, 20);
    // Кнопки управления
    b_determ = new QPushButton("Determinant", this);
    b_determ->setGeometry(300, 20, 80, 30);
    b_rank = new QPushButton("Rank", this);
    b_rank->setGeometry(300, 50, 80, 30);
    b_transp = new QPushButton("Transpose", this);
    b_transp->setGeometry(300, 80, 80, 30);
    // Текст с результатом
    op_result = new QLabel("Operate on the matrix using buttons and text fields above...", this);
    op_result->setGeometry(20, 190, 320, 75);
    // Соединение сигналов и слотов
    connect(b_determ, SIGNAL(pressed()), this, SLOT(determinant()));
    connect(b_rank, SIGNAL(pressed()), this, SLOT(rank()));
    connect(b_transp, SIGNAL(pressed()), this, SLOT(transpose()));
}

TInterface::~TInterface()
{
    delete n1;
    delete n1_num;
    delete n1_deno;
    delete n2;
    delete n2_num;
    delete n2_deno;
    delete n3;
    delete n3_num;
    delete n3_deno;
    delete n4;
    delete n4_num;
    delete n4_deno;
    delete n5;
    delete n5_num;
    delete n5_deno;
    delete n6;
    delete n6_num;
    delete n6_deno;
    delete n7;
    delete n7_num;
    delete n7_deno;
    delete n8;
    delete n8_num;
    delete n8_deno;
    delete n9;
    delete n9_num;
    delete n9_deno;

    delete b_determ;
    delete b_rank;
    delete b_transp;

    delete op_result;
}

/*
 * Собрать матрицу из значений элементов интерфейса
 */
matrix TInterface::make() {
    TRational r1(n1_num->text().toInt(), n1_deno->text().toInt());
    TRational r2(n2_num->text().toInt(), n2_deno->text().toInt());
    TRational r3(n3_num->text().toInt(), n3_deno->text().toInt());
    TRational r4(n4_num->text().toInt(), n4_deno->text().toInt());
    TRational r5(n5_num->text().toInt(), n5_deno->text().toInt());
    TRational r6(n6_num->text().toInt(), n6_deno->text().toInt());
    TRational r7(n7_num->text().toInt(), n7_deno->text().toInt());
    TRational r8(n8_num->text().toInt(), n8_deno->text().toInt());
    TRational r9(n9_num->text().toInt(), n9_deno->text().toInt());
    matrix m = matrix(3);
    m.init(new number[9] {r1, r2, r3, r4, r5, r6, r7, r8, r9}, 3);
    return m;
}

/*
 * Вычислить определитель и показать результат
 */
void TInterface::determinant() {
    try {
        matrix m = make();
        QString r("Determinant: ");
        r << m.determ();
        op_result->setText(r);
    } catch (std::runtime_error e) {
        op_result->setText(QString("Determinant calculation failed: ") + e.what());
    }
}

/*
 * Вычислить ранг и показать результат
 */
void TInterface::rank() {
    try {
        matrix m = make();
        QString r("Rank: ");
        r += QString().setNum(m.rank());
        op_result->setText(r);
    } catch (std::runtime_error e) {
        op_result->setText(QString("Rank calculation failed: ") + e.what());
    }
}

/*
 * Транспонировать матрицу и показать результат
 */
void TInterface::transpose() {
    try {
        matrix m = make();
        m.transp();
        QString r("Transposed matrix = ");
        r << m;
        op_result->setText(r);
    } catch (std::runtime_error e) {
        op_result->setText(QString("Transposing failed: ") + e.what());
    }
}
