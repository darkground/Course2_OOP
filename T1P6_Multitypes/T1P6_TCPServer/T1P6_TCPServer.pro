QT = core network

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../T1P6_Shared/connector.cpp \
        ../T1P6_Shared/shared.cpp \
        application.cpp \
        complex.cpp \
        main.cpp \
        rational.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += ../T1P6_Shared/

HEADERS += \
    ../T1P6_Shared/connector.h \
    ../T1P6_Shared/shared.h \
    application.h \
    complex.h \
    matrix.h \
    matrixsquare.h \
    rational.h
