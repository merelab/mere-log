#ifndef MERELOGHANDLER_H
#define MERELOGHANDLER_H

#include "../merelog.h"
#include "../merelogconfig.h"

class MereLogHandler
{
public:
//    virtual ~MereLogHandler();
    MereLogHandler(MereLogConfig *config);
    virtual bool handle(MereLog *log) = 0;

protected:
    MereLogConfig *m_config;
};

#endif // MERELOGHANDLER_H
