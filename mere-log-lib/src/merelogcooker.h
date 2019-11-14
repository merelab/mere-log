#ifndef MERELOGGERWORKER_H
#define MERELOGGERWORKER_H

#include "merelog.h"
#include "merelogconfig.h"
#include "merelogdispatcher.h"

#include <QThread>
#include <QObject>
#include <QDebug>

class MereLogCooker : public QObject
{
    Q_OBJECT
public:
    ~MereLogCooker();
    explicit MereLogCooker(MereLogConfig *config, QObject *parent = nullptr);

signals:
    bool dispatch(MereLog *log);

public slots:
    bool log(const QString &message);
    bool log(MereLog::Severity severity, const QString &message);
    bool log(MereLog *log);

private:
    MereLogConfig *m_config;
    MereLogDispatcher *m_dispatcher;
};

#endif // MERELOGGERWORKER_H
