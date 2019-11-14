#include "merelogger.h"

MereLogger::~MereLogger()
{
    m_thread->quit();
    m_thread->wait();
}

MereLogger::MereLogger(MereLogConfig *config, QObject *parent)
    : QObject(parent),
      m_config(config),
      m_thread(new QThread(this)),
      m_cooker(new MereLogCooker(config))
{
    qRegisterMetaType<MereLog::Severity>("MereLog::Severity");

    m_cooker->moveToThread(m_thread);

    connect(this, SIGNAL(log(const QString &)), m_cooker, SLOT(log(const QString &)));
    connect(this, SIGNAL(log(MereLog::Severity, const QString &)), m_cooker, SLOT(log(MereLog::Severity, const QString &)));
    connect(this, SIGNAL(log(MereLog *)), m_cooker, SLOT(log(MereLog *)));

    connect(m_thread, &QThread::finished, m_cooker, &QObject::deleteLater);

    m_thread->start();
}

MereLogConfig* MereLogger::config() const
{
    return m_config;
}
