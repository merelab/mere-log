#ifndef MERELOGDISPATCHER_H
#define MERELOGDISPATCHER_H

#include "merelog.h"
#include "merelogconfig.h"
#include "handler/mereloghandler.h"

#include <QObject>
#include <QDebug>

class MereLogDispatcher : public QObject
{
    Q_OBJECT
public:
    ~MereLogDispatcher();
    explicit MereLogDispatcher(MereLogConfig *config, QObject *parent = nullptr);

signals:
    bool handle(MereLog *log);

public slots:
    bool dispatch(MereLog *log);

private:
    MereLogConfig *m_config;

    QThread *m_thread;
//    QList<MereLogHandler *> m_handlers;
};

#endif // MERELOGDISPATCHER_H
