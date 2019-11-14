#ifndef MERELOGGER_H
#define MERELOGGER_H

#include "merelog.h"
#include "merelogconfig.h"
#include "merelogcooker.h"
#include "merelog.h"

#include <QThread>
#include <QObject>

class MERE_LOG_LIBSPEC MereLogger : public QObject
{
    Q_OBJECT
public:
    virtual ~MereLogger();
    explicit MereLogger(MereLogConfig *config, QObject *parent = nullptr);

    virtual bool emergency(const QString &message) = 0;
    virtual bool alert(const QString &message) = 0;
    virtual bool critical(const QString &message) = 0;
    virtual bool error(const QString &message) = 0;
    virtual bool warning(const QString &message) = 0;
    virtual bool notice(const QString &message) = 0;
    virtual bool info(const QString &message) = 0;
    virtual bool debug(const QString &message) = 0;

protected:
    MereLogConfig *config() const;

signals:
    bool log(const QString &message);
    bool log(MereLog::Severity severity, const QString &message);
    bool log(MereLog *log);

private:
    MereLogConfig *m_config;

    QThread *m_thread;
    MereLogCooker *m_cooker;
};

#endif // MERELOGGER_H
