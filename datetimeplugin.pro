QT              += widgets svg dbus 
TEMPLATE         = lib
CONFIG          += plugin c++11
 
TARGET           = $$qtLibraryTarget(datetimeplugin)
DESTDIR          = $$_PRO_FILE_PWD_
DISTFILES       += datetime.json
INCLUDEPATH     += /usr/include/libdtk-2.0.9/DCore

HEADERS += \
    datetimeplugin.h \
    datetimewidget.h \
    tipswidget.h
 
SOURCES += \
    datetimeplugin.cpp \
    datetimewidget.cpp \
    tipswidget.cpp
 
isEmpty(PREFIX) {
    PREFIX = /usr
}
 
target.path = $${PREFIX}/lib/dde-dock/plugins/
INSTALLS += target

RESOURCES += \
    datetime.qrc
