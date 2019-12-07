QT       += core gui network sql printsupport serialport multimedia multimediawidgets
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
    abonne.cpp \
    abonnement.cpp \
    adhir.cpp \
    amira.cpp \
    annonce.cpp \
    conge.cpp \
    connexion.cpp \
    employe.cpp \
    fiche.cpp \
    ligne.cpp \
    login1.cpp \
    main.cpp \
    mainwindow.cpp \
    malek.cpp \
    med.cpp \
    nadhir.cpp \
    panne.cpp \
    qcustomplot.cpp \
    reclamation.cpp \
    rouaa.cpp \
    smtp.cpp \
    station.cpp \
    statistique.cpp \
    ticket.cpp \
    vehicule.cpp

HEADERS += \
    abonne.h \
    abonnement.h \
    adhir.h \
    amira.h \
    annonce.h \
    conge.h \
    connexion.h \
    employe.h \
    fiche.h \
    ligne.h \
    login1.h \
    mainwindow.h \
    malek.h \
    med.h \
    nadhir.h \
    panne.h \
    qcustomplot.h \
    reclamation.h \
    rouaa.h \
    smtp.h \
    station.h \
    statistique.h \
    ticket.h \
    vehicule.h

FORMS += \
    adhir.ui \
    amira.ui \
    login1.ui \
    malek.ui \
    med.ui \
    nadhir.ui \
    rouaa.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
