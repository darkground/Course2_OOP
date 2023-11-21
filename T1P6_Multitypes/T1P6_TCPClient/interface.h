#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>

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
        *n1_first, *n2_first, *n3_first,
        *n4_first, *n5_first, *n6_first,
        *n7_first, *n8_first, *n9_first;

    // Ввод знаменателя
    QLineEdit
        *n1_second, *n2_second, *n3_second,
        *n4_second, *n5_second, *n6_second,
        *n7_second, *n8_second, *n9_second;

    // Смена типов
    QRadioButton
        *r_float, *r_complex, *r_rational;

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

public slots:
    void answer(QString);

private slots:
    void formRequest();

signals:
    void request(QString);
};

#endif // TINTERFACE_H
