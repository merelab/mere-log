include(../mere-log-lib/mere-log-lib.pri)

QT = core

TARGET = mere-log
TEMPLATE = app 

SOURCES += \
    main.cpp

HEADERS += \

#
# Install
#
unix {
    target.path = /usr/local/bin
    INSTALLS += target
}
