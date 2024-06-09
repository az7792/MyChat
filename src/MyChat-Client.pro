QT       += core gui network websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatform.cpp \
    chatwebsocket.cpp \
    FriendNotificationWindow.cpp \
    addform.cpp \
    contactmanager.cpp \
    formmanager.cpp \
    group.cpp \
    groupmanager.cpp \
    loginform.cpp \
    main.cpp \
    mainform.cpp \
    message.cpp \
    recvbox.cpp \
    registerform.cpp \
    resetpasswordform.cpp \
    sendbox.cpp \
    user.cpp \
    userinfomanager.cpp \
    contactform.cpp \
    contactmassage.cpp \
    groupform.cpp \
    groupmassage.cpp \
    mainwindow.cpp

HEADERS += \
    chatform.h \
    chatwebsocket.h \
    FriendNotificationWindow.h \
    addform.h \
    contactmanager.h \
    formmanager.h \
    group.h \
    groupmanager.h \
    logger.h \
    loginform.h \
    mainform.h \
    message.h \
    recvbox.h \
    registerform.h \
    resetpasswordform.h \
    sendbox.h \
    user.h \
    userinfomanager.h \
    contactform.h \
    contactmassage.h \
    groupform.h \
    groupmassage.h \
    mainwindow.h

FORMS += \
    chatform.ui \
    loginform.ui \
    mainform.ui \
    recvbox.ui \
    registerform.ui \
    resetpasswordform.ui \
    sendbox.ui \
    contactform.ui \
    contactmassage.ui \
    groupform.ui \
    groupmassage.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../../壁纸/原神壁纸/resources.qrc \
    resources.qrc

DISTFILES += \
    ../../../壁纸/原神壁纸/914037300.jpg
