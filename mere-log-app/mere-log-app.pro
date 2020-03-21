include(../mere-log-lib/mere-log-lib.pri)

QT = core

TARGET = mere-log
TEMPLATE = app 

SOURCES += \
    src/main.cpp

HEADERS += \

OTHER_FILES += \
    etc/log.conf

#
# Install
#
unix {
    target.path = /usr/local/bin
    INSTALLS += target
}
