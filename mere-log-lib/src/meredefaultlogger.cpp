#include "meredefaultlogger.h"
#include "merelog.h"

#include "filter/merelogdefaultfilter.h"

#include "processor/merelogdefaultprocessor.h"
#include "processor/mereloghostnameprocessor.h"
#include "processor/merelogapplicationprocessor.h"

#include "handler/merelogsysloghandler.h"

#include <QListIterator>

MereDefaultLogger::MereDefaultLogger(MereLogConfig *config)
    : MereLogger(config)
{
    MereLogProcessor *hostnameProcessor = new MereLogHostnameProcessor();
    config->addProcessor(hostnameProcessor);

    MereLogProcessor *appProcessor = new MereLogApplicationProcessor();
    config->addProcessor(appProcessor);

    //    MereLogFilter *filter = new MereLogDefaultFilter();
    //    config->addFilter(filter);
}

bool MereDefaultLogger::emergency(const QString &message)
{
    return true;
}

bool MereDefaultLogger::alert(const QString &message)
{
    return true;
}

bool MereDefaultLogger::critical(const QString &message)
{
    return true;
}

bool MereDefaultLogger::error(const QString &message)
{
    return true;
}

bool MereDefaultLogger::warning(const QString &message)
{
    return true;
}

bool MereDefaultLogger::notice(const QString &message)
{
    return true;
}

bool MereDefaultLogger::info(const QString &message)
{
    MereLog *log = new MereLog(MereLog::Informational, message);

    return this->log(log);
}

bool MereDefaultLogger::debug(const QString &message)
{

}

bool MereDefaultLogger::log(MereLog *log)
{
    MereLogConfig *config = this->config();
    config->setSeverities(MereLog::Severity::All);

    // pre-filters
    MereLogFilter *mask = config->mask();
    if(!mask->filter(log)) return false;

    // processors
    QList<MereLogProcessor *> processors = config->processors();
    QListIterator<MereLogProcessor *> pit(processors);
    while (pit.hasNext())
    {
        MereLogProcessor *processore = pit.next();
        processore->process(log);
    }

    // post-filters
    QList<MereLogFilter *> filters = config->filters();
    QListIterator<MereLogFilter *> fit(filters);
    while (fit.hasNext())
    {
        MereLogFilter *filter = fit.next();
        if (!filter->filter(log))
            return false;
    }

    MereLogSyslogHandler *handler = new MereLogSyslogHandler(config);
    handler->handle(log);

    return true;
}
