QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../T1P4_Shared/

SOURCES += \
    ../T1P4_Shared/shared.cpp \
    ../T1P4_Shared/connector.cpp \
    application.cpp \
    interface.cpp \
    main.cpp

HEADERS += \
    ../T1P4_Shared/shared.h \
    ../T1P4_Shared/connector.h \
    application.h \
    interface.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
