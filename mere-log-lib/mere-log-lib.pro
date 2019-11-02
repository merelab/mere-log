QT += core

CONFIG += c++11
CONFIG += shared

TARGET = mere-log
VERSION = 0.0.1b
TEMPLATE = lib

DEFINES += QT_DEPRECATED_WARNINGS MERE_LOG_LIB

DEFINES += LIB_CODE=\\\"$$TARGET\\\"
DEFINES += LIB_NAME=\\\"$$TARGET\\\"
DEFINES += LIB_VERSION=\\\"$$VERSION\\\"

CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

SOURCES += \

HEADERS += \

DESTDIR = $$PWD/../lib

#
# Install
#
unix {
    target.path = /usr/local/lib
    INSTALLS += target

    INSTALL_PREFIX = /usr/local/include/mere/log
    for(header, HEADERS) {
        sdir = $${dirname(header)}
        sdir = $$replace(sdir, "src", "")
        path = $${INSTALL_PREFIX}$${sdir}

        eval(headers_$${path}.files += $$header)
        eval(headers_$${path}.path = $$path)
        eval(INSTALLS *= headers_$${path})
    }
}

