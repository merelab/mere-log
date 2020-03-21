#ifndef MEREDEFAULTLOGGER_H
#define MEREDEFAULTLOGGER_H

#include "merelogger.h"
#include "filter/merelogfilter.h"

class MERE_LOG_LIBSPEC MereDefaultLogger : public MereLogger
{
    Q_OBJECT
public:
    explicit MereDefaultLogger(MereLogConfig *config, QObject *parent = nullptr);

    bool emergency(const QString &message);
    bool alert(const QString &message);
    bool critical(const QString &message);
    bool error(const QString &message);
    bool warning(const QString &message);
    bool notice(const QString &message);
    bool info(const QString &message);
    bool debug(const QString &message);

private:
    void loadFilters();
    void loadProcessors();
};

#endif // MEREDEFAULTLOGGER_H
