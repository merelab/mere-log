#include "merelogconfig.h"
#include "filter/merelogseverityfilter.h"

MereLogConfig::MereLogConfig(QObject *parent)
    : QObject(parent),
      m_severities(0),
      m_filter(new MereLogSeverityFilter(this))
{

}

bool MereLogConfig::isFilterEnabled(const QString &filter)
{
    return true;
}

bool MereLogConfig::isProcessorEnabled(const QString &processor)
{
    return true;
}

bool MereLogConfig::isHandlerEnabled(const QString &handler)
{
    return true;
}

int MereLogConfig::severities() const
{
    return m_severities;
}

void MereLogConfig::setSeverities(int severities)
{
    m_severities = severities;
}

MereLogFilter* MereLogConfig::mask() const
{
    return m_filter;
}

bool MereLogConfig::addProcessor(MereLogProcessor *processor)
{
    m_processors.append(processor);

    return true;
}

bool MereLogConfig::addProcessors(QList<MereLogProcessor *> processors)
{
    m_processors.clear();
    m_processors.append(processors);
    return true;
}

QList<MereLogProcessor *> MereLogConfig::processors() const
{
    return m_processors;
}

QList<MereLogFilter *> MereLogConfig::filters() const
{
    return m_filters;
}

bool MereLogConfig::setFilters(QList<MereLogFilter *> filters)
{
    m_filters.clear();
    m_filters.append(filters);
    return true;
}

bool MereLogConfig::addFilter(MereLogFilter *filter)
{
    m_filters.append(filter);

    return true;
}
