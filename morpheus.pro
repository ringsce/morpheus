QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 sdk_no_version_check multimedia


QMAKE_MACOSX_DEPLOYMENT_TARGET = 11.0
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x040000    # disables all the APIs deprecated before Qt 6.0.0

ICON = resources/icon.icns
SOURCES += \
    src/db/db.cpp \
    src/db/isam.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    src/db/db.h \
    src/db/isam.h \
    src/mainwindow.h \

FORMS += \
    src/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \

DISTFILES += \
    CMakeLists.txt \
    LICENSE \
    License.txt \
    RINGSCE_v2.png \
    libs/updater/CMakeLists.txt

RESOURCES += \
    resources.qrc

QMAKE_APPLE_DEVICE_ARCHS="x86_64 i686"
