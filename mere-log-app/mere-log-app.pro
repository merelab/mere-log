include(../mere-log-lib/mere-log-lib.pri)

QT = core

TARGET = mere-log
TEMPLATE = app 

SOURCES += \
    src/main.cpp

HEADERS += \

OTHER_FILES += \
    etc/log.conf

LIBS        += -L /usr/local/lib
INCLUDEPATH += -I /usr/local/include


#
# Install
#
unix {
    target.path = /usr/local/bin
    INSTALLS += target
}
