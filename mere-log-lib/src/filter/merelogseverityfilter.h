#ifndef MERELOGSEVERITYFILTER_H
#define MERELOGSEVERITYFILTER_H

#include "merelogfilter.h"
#include "../merelog.h"
#include "../merelogconfig.h"

class MereLogSeverityFilter : public MereLogFilter
{
public:
    explicit MereLogSeverityFilter(MereLogConfig *config);
    bool filter(MereLog *log) override;

private:
    MereLogConfig *m_config;
};

#endif // MERELOGSEVERITYFILTER_H
