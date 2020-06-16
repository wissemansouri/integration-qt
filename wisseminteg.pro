QT       += core gui sql  \
    quick
QT       += printsupport
QT       += core
QT       += core gui network
QT       += core gui
QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    actualites.cpp \
    connexion.cpp \
    dialog_home.cpp \
    dialog_inscription.cpp \
    evenement.cpp \
    gestion_lev.cpp \
    gestion_pas.cpp \
    gestion_sj.cpp \
    joueur.cpp \
    localisation.cpp \
    main.cpp \
    mainwindow.cpp \
    personnel.cpp \
    publicite.cpp \
    sponsor.cpp \
    sport.cpp \
    statt.cpp

HEADERS += \
    actualites.h \
    connexion.h \
    dialog_home.h \
    dialog_inscription.h \
    evenement.h \
    gestion_lev.h \
    gestion_pas.h \
    gestion_sj.h \
    joueur.h \
    localisation.h \
    mainwindow.h \
    personnel.h \
    publicite.h \
    sponsor.h \
    sport.h \
    statt.h

FORMS += \
    dialog_home.ui \
    dialog_inscription.ui \
    gestion_lev.ui \
    gestion_pas.ui \
    gestion_sj.ui \
    mainwindow.ui \
    statt.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc
