#include "meredefaultlogger.h"
#include "merelog.h"

#include "processor/merelogdefaultprocessor.h"
#include "processor/mereloghostnameprocessor.h"
#include "processor/merelogusernameprocessor.h"
#include "processor/merelogprocessprocessor.h"
#include "processor/merelogapplicationprocessor.h"

MereDefaultLogger::MereDefaultLogger(MereLogConfig *config, QObject *parent)
    : MereLogger(config, parent)
{
    MereLogProcessor *hostnameProcessor = new MereLogHostnameProcessor();
    config->addProcessor(hostnameProcessor);

    MereLogProcessor *userProcessor = new MereLogUsernameProcessor();
    config->addProcessor(userProcessor);

    MereLogProcessor *appProcessor = new MereLogApplicationProcessor();
    config->addProcessor(appProcessor);

    MereLogProcessor *processProcessor = new MereLogProcessProcessor();
    config->addProcessor(processProcessor);
}

bool MereDefaultLogger::emergency(const QString &message)
{
    MereLog *log = new MereLog(MereLog::Emergency, message);

    return this->log(log);
}

bool MereDefaultLogger::alert(const QString &message)
{
    MereLog *log = new MereLog(MereLog::Alert, message);

    return this->log(log);
}

bool MereDefaultLogger::critical(const QString &message)
{
    MereLog *log = new MereLog(MereLog::Critical, message);

    return this->log(log);
}

bool MereDefaultLogger::error(const QString &message)
{
    MereLog *log = new MereLog(MereLog::Error, message);

    return this->log(log);
}

bool MereDefaultLogger::warning(const QString &message)
{
    MereLog *log = new MereLog(MereLog::Warning, message);

    return this->log(log);
}

bool MereDefaultLogger::notice(const QString &message)
{
    MereLog *log = new MereLog(MereLog::Notice, message);

    return this->log(log);

}

bool MereDefaultLogger::info(const QString &message)
{
    MereLog *log = new MereLog(MereLog::Informational, message);

    return this->log(log);
}

bool MereDefaultLogger::debug(const QString &message)
{
    MereLog *log = new MereLog(MereLog::Debug, message);

    return this->log(log);
}
