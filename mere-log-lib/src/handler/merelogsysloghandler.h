#ifndef MERELOGSYSLOGHANDLER_H
#define MERELOGSYSLOGHANDLER_H

#include "mereloghandler.h"

#include <QDebug>

class MereLogSyslogHandler : public MereLogHandler
{
public:
    MereLogSyslogHandler(MereLogConfig *config);

    bool handle(MereLog *log);
};

#endif // MERELOGSYSLOGHANDLER_H
