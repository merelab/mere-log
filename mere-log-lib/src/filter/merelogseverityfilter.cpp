#include "merelogseverityfilter.h"

MereLogSeverityFilter::MereLogSeverityFilter(MereLogConfig *config)
    : MereLogFilter(config), m_config(config)
{

}

bool MereLogSeverityFilter::filter(MereLog *log)
{
    int flags = m_config->severities();

    int what = log->what();

    return (flags & what) == what;
}
