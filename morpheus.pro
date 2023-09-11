QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 sdk_no_version_check

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x040000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/secWindow.cpp \
    src/db.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    src/db.h \
    src/mainwindow.h \
    src/secwindow.h

FORMS += \
    src/secWindow.ui \
    src/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \

DISTFILES += \
    CMakeLists.txt \
    License.txt \
    libs/updater/CMakeLists.txt

RESOURCES += \
    resources.qrc
