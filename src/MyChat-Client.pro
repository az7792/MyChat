QT       += core gui network websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatform.cpp \
    chatwebsocket.cpp \
    formmanager.cpp \
    loginform.cpp \
    main.cpp \
    registerform.cpp \
    resetpasswordform.cpp \
    user.cpp \
    userinfomanager.cpp

HEADERS += \
    chatform.h \
    chatwebsocket.h \
    formmanager.h \
    logger.h \
    loginform.h \
    registerform.h \
    resetpasswordform.h \
    user.h \
    userinfomanager.h

FORMS += \
    chatform.ui \
    loginform.ui \
    registerform.ui \
    resetpasswordform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
