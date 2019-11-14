#include "merelogcooker.h"

MereLogCooker::~MereLogCooker()
{
    if (m_dispatcher)
    {
        delete m_dispatcher;
        m_dispatcher = nullptr;
    }
}

MereLogCooker::MereLogCooker(MereLogConfig *config, QObject *parent)
    : QObject(parent),
      m_config(config),
      m_dispatcher(new MereLogDispatcher(config))
{
    connect(this, SIGNAL(dispatch(MereLog *)), m_dispatcher, SLOT(dispatch(MereLog *)));
}

bool MereLogCooker::log(const QString &message)
{
    qDebug() << "Lets work!";

    return this->log(MereLog::Informational, message);
}

bool MereLogCooker::log(MereLog::Severity severity, const QString &message)
{
    qDebug() << "Lets log.it! " << severity << message;

    MereLog *log = new MereLog(severity, message);

    return this->log(log);
}

bool MereLogCooker::log(MereLog *log)
{
    qDebug() << "Working... " << log;

    m_config->setSeverities(MereLog::Severity::All);

    // pre-filters
    MereLogFilter *mask = m_config->mask();
    if(!mask->filter(log)) return false;

    // processors
    QList<MereLogProcessor *> processors = m_config->processors();
    QListIterator<MereLogProcessor *> pit(processors);
    while (pit.hasNext())
    {
        MereLogProcessor *processore = pit.next();
        processore->process(log);
    }

    // post-filters
    QList<MereLogFilter *> filters = m_config->filters();
    QListIterator<MereLogFilter *> fit(filters);
    while (fit.hasNext())
    {
        MereLogFilter *filter = fit.next();
        if (!filter->filter(log))
            return false;
    }
    qDebug() << "Yes! Done!";
    this->dispatch(log);

    return true;
}


