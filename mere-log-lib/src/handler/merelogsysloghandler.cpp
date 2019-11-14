#include "merelogsysloghandler.h"
#include "../format/merelogsyslogformatter.h"

#include <QThread>
MereLogSyslogHandler::MereLogSyslogHandler(MereLogConfig *config, QObject *parent)
    : MereLogHandler(config, parent)
{

}

bool MereLogSyslogHandler::handle(MereLog *log)
{
    qDebug() << "Yes, please dump to the syslog!" << log->get("hostname");

    int what = 0;
    switch (log->what())
    {
        case MereLog::Emergency:
            what = LOG_EMERG;
            break;

        case MereLog::Alert:
            what = LOG_ALERT;
            break;

        case MereLog::Critical:
            what = LOG_CRIT;
            break;

        case MereLog::Error:
            what = LOG_ERR;
            break;

        case MereLog::Warning:
            what = LOG_WARNING;
            break;

        case MereLog::Notice:
            what = LOG_NOTICE;
            break;

        case MereLog::Informational:
            what = LOG_INFO;
            break;

        case MereLog::Debug:
            what = LOG_DEBUG;
            break;
    }


    MereLogSyslogFormatter fomatter(m_config);

    QString format = fomatter.format(log);

//    setlogmask (LOG_UPTO (LOG_DEBUG));

    openlog("mere-log", (LOG_CONS|LOG_PERROR), LOG_DAEMON);

    syslog(what, "%s", format.toStdString().data());

    closelog ();

    return true;
}
