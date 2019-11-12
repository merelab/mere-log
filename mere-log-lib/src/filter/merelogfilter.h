#ifndef MERELOGFILTER_H
#define MERELOGFILTER_H

#include "../merelog.h"
//#include "../merelogconfig.h"

class MereLogConfig;

class MereLogFilter
{
public:
//    virtual ~MereLogFilter();
    MereLogFilter(MereLogConfig *config);
    virtual bool filter(MereLog *log) = 0;

protected:
    MereLogConfig* config() const;


protected:
    MereLogConfig *m_config;
};

#endif // MERELOGFILTER_H
