QT += quick qml network positioning location sql widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    data/ChatRecordListData.h \
    db/ChatRecordDBOperate.h \
    db/ChatUserDBOperate.h \
    data/ChatUserListData.h \
    db/DBOperateBase.h \
    manager/CharRecordManager.h \
    manager/ChatUserManager.h \
    manager/Manager.h \
    model/ChatRecordModel.h \
    model/ChatUserModel.h

SOURCES += \
        data/ChatRecordListData.cpp \
        db/ChatRecordDBOperate.cpp \
        db/ChatUserDBOperate.cpp \
        data/ChatUserListData.cpp \
        db/DBOperateBase.cpp \
        manager/CharRecordManager.cpp \
        manager/ChatUserManager.cpp \
        manager/Manager.cpp \
        model/ChatRecordModel.cpp \
        model/ChatUserModel.cpp \
        main.cpp

RESOURCES += qml.qrc

TRANSLATIONS += \
    chat_zh_CN.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
