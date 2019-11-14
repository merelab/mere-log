#include "merelogdispatcher.h"
#include "handler/merelogsysloghandler.h"

#include <QThread>

MereLogDispatcher::~MereLogDispatcher()
{
    m_thread->quit();
    m_thread->wait();
}

MereLogDispatcher::MereLogDispatcher(MereLogConfig *config, QObject *parent)
    : QObject(parent),
      m_config(config),
      m_thread(new QThread(this))
{
    MereLogSyslogHandler *handler = new MereLogSyslogHandler(config);
    handler->moveToThread(m_thread);

    connect(this, SIGNAL(handle(MereLog *)), handler, SLOT(handle(MereLog *)));
    connect(m_thread, SIGNAL(finished()), handler, SLOT(deleteLater()));

    m_thread->start();
}

bool MereLogDispatcher::dispatch(MereLog *log)
{
    return this->handle(log);
}
