#include "merelogger.h"
#include "merelogcooker.h"

MereLogger::~MereLogger()
{
    m_thread->quit();
    m_thread->wait();
}

MereLogger::MereLogger(MereLogConfig *config, QObject *parent)
    : QObject(parent),
      m_config(config),
      m_thread(new QThread(this))
{
    qRegisterMetaType<MereLog::Severity>("MereLog::Severity");

    MereLogCooker *cooker = new MereLogCooker(config);

    cooker->moveToThread(m_thread);

    connect(this, SIGNAL(log(const QString &)), cooker, SLOT(log(const QString &)));
    connect(this, SIGNAL(log(MereLog::Severity, const QString &)), cooker, SLOT(log(MereLog::Severity, const QString &)));
    connect(this, SIGNAL(log(MereLog *)), cooker, SLOT(log(MereLog *)));

    connect(m_thread, SIGNAL(finished()), cooker, SLOT(deleteLater()));

    m_thread->start();
}

MereLogConfig* MereLogger::config() const
{
    return m_config;
}
