#ifndef MERELOGSYSLOGHANDLER_H
#define MERELOGSYSLOGHANDLER_H

#include "mereloghandler.h"

#include <syslog.h>

#include <QDebug>

class MereLogSyslogHandler : public MereLogHandler
{
    Q_OBJECT
public:
    MereLogSyslogHandler(MereLogConfig *config, QObject *parent = nullptr);

    bool handle(MereLog *log);

private slots:
//    void ready();
};

#endif // MERELOGSYSLOGHANDLER_H
