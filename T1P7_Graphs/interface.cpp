#include "interface.h"

QString& operator<< (QString& qs, qint16 i) {
    qs += QString().setNum(i);
    return qs;
}

TInterface::TInterface(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("OOP Practice #7");
    setFixedSize(300, 105);

    filelabel = new QLabel("Select graph file:", this);
    filelabel->setGeometry(100, 2, 295, 30);
    filename = new QLineEdit("No file selected.", this);
    filename->setGeometry(5, 30, 245, 30);
    filename->setEnabled(false);
    filename->setStyleSheet("color: gray");
    filechoose = new QPushButton("Select", this);
    filechoose->setGeometry(250, 30, 45, 30);

    result = new QLabel("...", this);
    result->setGeometry(5, 65, 295, 30);

    connect(filechoose, SIGNAL(pressed()), this, SLOT(openFile()));
}

TInterface::~TInterface()
{
}

Matrix<qint16>* TInterface::read(QString& filename) {
    QFile f(filename);
    if (!f.open(QFile::ReadOnly | QFile::Text)) return 0;
    QTextStream in(&f);
    bool success;
    unsigned m = in.readLine().toUInt(&success);
    if (!success || m == 0) return 0;
    unsigned n = in.readLine().toUInt(&success);
    if (!success || n == 0) return 0;
    vector<qint16> arr(m * n);
    for (unsigned i = 0; i < m * n; i++) {
        if (in.atEnd()) return 0;
        arr[i] = in.readLine().toShort();
    }
    Matrix<qint16>* matr = new Matrix<qint16>(m, n);
    matr->init(arr.data());
    return matr;
}

bool TInterface::isValid(Matrix<qint16>* matr) {
    for (unsigned i = 0; i < matr->getSizeX(); i++) {
        for (unsigned j = 0; j < matr->getSizeY(); j++) {
            if (matr->get(i, j) < 0) {
                return false;
            }
        }
    }
    return true;
}

void TInterface::openFile() {
    QString fi = QFileDialog::getOpenFileName(this, "Opening Graph...", QString(), "all (*.*);;graphs (*.txt)");
    if (!fi.isEmpty() && !fi.isNull()) {
        filename->setText(fi);
        Matrix<qint16>* matr = read(fi);
        if (matr == 0)
            result->setText("Selected file is not a graph");
        else {
            if (isValid(matr))
                result->setText("");
            else
                result->setText("Invalid matrix");
            delete matr;
        }
    }
}
