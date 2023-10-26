#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class TInterface : public QWidget
{
    Q_OBJECT

    // Текст ячейки слева от ввода значения
    QLabel
        *n1, *n2, *n3,
        *n4, *n5, *n6,
        *n7, *n8, *n9;

    // Ввод числителя
    QLineEdit
        *n1_num, *n2_num, *n3_num,
        *n4_num, *n5_num, *n6_num,
        *n7_num, *n8_num, *n9_num;

    // Ввод знаменателя
    QLineEdit
        *n1_deno, *n2_deno, *n3_deno,
        *n4_deno, *n5_deno, *n6_deno,
        *n7_deno, *n8_deno, *n9_deno;

    // Кнопки управления
    QPushButton
        *b_transp,
        *b_rank,
        *b_determ;

    // Текст с результатом
    QLabel *op_result;

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();

    //matrix make();
//public slots:
    //void determinant();
    //void rank();
    //void transpose();
};

#endif // TINTERFACE_H
