#include "application.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    TApplication a(argc, argv);
    return a.exec();
}
