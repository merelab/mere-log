#include "merelogdispatcher.h"
#include "handler/merelogsysloghandler.h"

#include <QThread>

MereLogDispatcher::~MereLogDispatcher()
{

}

MereLogDispatcher::MereLogDispatcher(MereLogConfig *config, QObject *parent)
    : QObject(parent),
      m_config(config),
      m_thread(new QThread(this))
{
    MereLogSyslogHandler *handler = new MereLogSyslogHandler(config);
    handler->moveToThread(m_thread);

    connect(this, SIGNAL(handle(MereLog *)), handler, SLOT(handle(MereLog *)));
    connect(m_thread, &QThread::finished, handler, &QObject::deleteLater);

    m_handlers.append(handler);

    m_thread->start();
}

bool MereLogDispatcher::dispatch(MereLog *log)
{
    qDebug() << "Dispatcher thread:" << this->thread();

    qDebug() << "Going to send it off";
    this->handle(log);
    return true;
}
