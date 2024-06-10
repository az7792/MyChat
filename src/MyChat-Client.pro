QT       += core gui network websockets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    entity/group.cpp \
    entity/message.cpp \
    entity/user.cpp \
    largeWidget/mainform.cpp \
    main.cpp \
    manager/databasemanager.cpp \
    manager/formmanager.cpp \
    manager/userinfomanager.cpp \
    mediumWidget/FriendNotificationWindow.cpp \
    mediumWidget/addform.cpp \
    mediumWidget/chatform.cpp \
    mediumWidget/contactform.cpp \
    mediumWidget/groupform.cpp \
    mediumWidget/messagelistform.cpp \
    smallWidget/contactmassage.cpp \
    smallWidget/groupmassage.cpp \
    smallWidget/loginform.cpp \
    smallWidget/messagebox.cpp \
    smallWidget/recvbox.cpp \
    smallWidget/registerform.cpp \
    smallWidget/resetpasswordform.cpp \
    smallWidget/sendbox.cpp \
    webSocket/chatwebsocket.cpp


HEADERS += \
    entity/group.h \
    entity/message.h \
    entity/user.h \
    largeWidget/mainform.h \
    manager/databasemanager.h \
    manager/formmanager.h \
    manager/userinfomanager.h \
    mediumWidget/FriendNotificationWindow.h \
    mediumWidget/addform.h \
    mediumWidget/chatform.h \
    mediumWidget/contactform.h \
    mediumWidget/groupform.h \
    mediumWidget/messagelistform.h \
    smallWidget/contactmassage.h \
    smallWidget/groupmassage.h \
    smallWidget/loginform.h \
    smallWidget/messagebox.h \
    smallWidget/recvbox.h \
    smallWidget/registerform.h \
    smallWidget/resetpasswordform.h \
    smallWidget/sendbox.h \
    webSocket/chatwebsocket.h


FORMS += \
    largeWidget/mainform.ui \
    mediumWidget/chatform.ui \
    mediumWidget/contactform.ui \
    mediumWidget/groupform.ui \
    mediumWidget/messagelistform.ui \
    smallWidget/contactmassage.ui \
    smallWidget/groupmassage.ui \
    smallWidget/loginform.ui \
    smallWidget/messagebox.ui \
    smallWidget/recvbox.ui \
    smallWidget/registerform.ui \
    smallWidget/resetpasswordform.ui \
    smallWidget/sendbox.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../../壁纸/原神壁纸/resources.qrc \
    resources.qrc

DISTFILES += \
    ../../../壁纸/原神壁纸/914037300.jpg
