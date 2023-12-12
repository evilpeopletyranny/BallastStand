QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    algorithmcore.cpp \
    ballastresistorinputframe.cpp \
    calculationscreen.cpp \
    calculationsettingscreen.cpp \
    calculationstackedwidget.cpp \
    datahandler.cpp \
    main.cpp \
    mainwindow.cpp \
    resistor.cpp \
    resistorviewframe.cpp \
    tablewidget.cpp \
    utilityresistorinputframe.cpp \
    windowmanager.cpp

HEADERS += \
    algorithmcore.h \
    ballastresistorinputframe.h \
    calculationscreen.h \
    calculationsettingscreen.h \
    calculationstackedwidget.h \
    datahandler.h \
    mainwindow.h \
    resistor.h \
    resistorviewframe.h \
    tablewidget.h \
    utilityresistorinputframe.h \
    windowmanager.h

FORMS += \
    ballastresistorinputframe.ui \
    calculationscreen.ui \
    calculationsettingscreen.ui \
    calculationstackedwidget.ui \
    mainwindow.ui \
    resistorviewframe.ui \
    utilityresistorinputframe.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
