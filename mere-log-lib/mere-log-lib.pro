QT      = core

CONFIG += c++11
CONFIG += shared

TARGET = mere-log
VERSION = 0.0.1
TEMPLATE = lib

DEFINES += LIB_CODE=\\\"log\\\"
DEFINES += LIB_NAME=\\\"$$TARGET\\\"
DEFINES += LIB_VERSION=\\\"$$VERSION\\\"
DEFINES += QT_DEPRECATED_WARNINGS MERE_LOG_LIB

#CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

SOURCES += \
    src/filter/merelogseverityfilter.cpp \
    src/format/merelogsyslogformatter.cpp \
    src/handler/merelogdefaulthandler.cpp \
    src/handler/merelogfilehandler.cpp \
    src/handler/mereloghandler.cpp \
    src/handler/merelogsysloghandler.cpp \
    src/meredefaultlogger.cpp \
    src/merelog.cpp \
    src/merelogconfig.cpp \
    src/merelogcooker.cpp \
    src/merelogdispatcher.cpp \
    src/merelogfactory.cpp \
    src/filter/merelogfilter.cpp \
    src/filter/merelogdefaultfilter.cpp \
    src/format/merelogformatter.cpp \
    src/format/merelogdefaultformatter.cpp \
    src/merelogger.cpp \
    src/processor/merelogapplicationprocessor.cpp \
    src/processor/mereloghostnameprocessor.cpp \
    src/processor/merelogprocessor.cpp \
    src/processor/merelogdefaultprocessor.cpp \
    src/processor/merelogprocessprocessor.cpp \
    src/processor/merelogusernameprocessor.cpp

HEADERS += \
    src/filter/merelogseverityfilter.h \
    src/format/merelogsyslogformatter.h \
    src/handler/merelogdefaulthandler.h \
    src/handler/merelogfilehandler.h \
    src/handler/mereloghandler.h \
    src/handler/merelogsysloghandler.h \
    src/meredefaultlogger.h \
    src/merelog.h \
    src/merelogconfig.h \
    src/filter/merelogdefaultfilter.h \
    src/format/merelogdefaultformatter.h \
    src/merelogcooker.h \
    src/merelogdispatcher.h \
    src/merelogfactory.h \
    src/filter/merelogfilter.h \
    src/format/merelogformatter.h \
    src/merelogger.h \
    src/merelogglobal.h \
    src/processor/merelogapplicationprocessor.h \
    src/processor/mereloghostnameprocessor.h \
    src/processor/merelogprocessor.h \
    src/processor/merelogdefaultprocessor.h \
    src/processor/merelogprocessprocessor.h \
    src/processor/merelogusernameprocessor.h

DESTDIR = $$PWD/../lib

defineTest(copy) {
    source = $$1
    target = $$2

    for(file, source) {
        sdir = $${dirname(file)}
        sdir = $$replace(sdir, "src", "")
        path = $${target}$${sdir}

        QMAKE_POST_LINK += $$QMAKE_MKDIR $$quote($$path) $$escape_expand(\\n\\t)
        QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$file) $$quote($$path) $$escape_expand(\\n\\t)
    }

    export(QMAKE_POST_LINK)
}

copy($$HEADERS, $$PWD/../include/mere/log)

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

