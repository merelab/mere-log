#ifndef MERELOGCONFIG_H
#define MERELOGCONFIG_H

#include "merelogglobal.h"
#include "filter/merelogfilter.h"
#include "processor/merelogprocessor.h"

#include <QObject>

class MERE_LOG_LIBSPEC MereLogConfig : public QObject
{
    Q_OBJECT
public:
    explicit MereLogConfig(QObject *parent = nullptr);

    int severities() const;
    void setSeverities(int severities);

    MereLogFilter* mask() const;

    bool addProcessor(MereLogProcessor *processor);
    bool addProcessors(QList<MereLogProcessor *> processors);
    QList<MereLogProcessor *> processors() const;

    bool addFilter(MereLogFilter *mask);
    bool setFilters(QList<MereLogFilter *> filters);
    QList<MereLogFilter *> filters() const;


//signals:

//public slots:

private:
    int m_severities;

    MereLogFilter *m_filter;
    QList<MereLogFilter *> m_filters;
    QList<MereLogProcessor *> m_processors;
};

#endif // MERELOGCONFIG_H
