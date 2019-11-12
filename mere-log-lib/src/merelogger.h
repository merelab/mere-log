#ifndef MERELOGGER_H
#define MERELOGGER_H

#include "merelogglobal.h"
#include "merelog.h"
#include "merelogconfig.h"

#include <QList>

class MERE_LOG_LIBSPEC MereLogger
{
public:
//    virtual ~MereLogger();
    explicit MereLogger(MereLogConfig *config);

    virtual bool emergency(const QString &message) = 0;
    virtual bool alert(const QString &message) = 0;
    virtual bool critical(const QString &message) = 0;
    virtual bool error(const QString &message) = 0;
    virtual bool warning(const QString &message) = 0;
    virtual bool notice(const QString &message) = 0;
    virtual bool info(const QString &message) = 0;
    virtual bool debug(const QString &message) = 0;
//    virtual bool trace(const QString &message) = 0;

    virtual bool log(const QString &message){ return info(message); }

protected:
    virtual bool log(MereLog *log) = 0;
    MereLogConfig *config() const;

private:
    MereLogConfig *m_config;

//    MereLog *m_log;
//    QList<MereLogFilter *> m_filters;
//    QList<MereLogProcessor *> m_handlers;
};

#endif // MERELOGGER_H
