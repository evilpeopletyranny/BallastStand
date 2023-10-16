QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculationscreen.cpp \
    calculationsettingscreen.cpp \
    calculationstackedwidget.cpp \
    datahandler.cpp \
    main.cpp \
    mainwindow.cpp \
    resistor.cpp \
    resistorframe.cpp \
    resistorinputframe.cpp

HEADERS += \
    calculationscreen.h \
    calculationsettingscreen.h \
    calculationstackedwidget.h \
    datahandler.h \
    mainwindow.h \
    resistor.h \
    resistorframe.h \
    resistorinputframe.h

FORMS += \
    calculationscreen.ui \
    calculationsettingscreen.ui \
    calculationstackedwidget.ui \
    mainwindow.ui \
    resistorframe.ui \
    resistorinputframe.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
