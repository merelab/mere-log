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

    QString format = "${uuid} ${severity} ${timestamp} ${hostname} ${application} ${message}";

    MereLogSyslogFormatter fomatter(m_config);

    qDebug() << "1..." << format;
    qDebug() << "2..." << fomatter.format(log);
    qDebug() << "CCCThread:" << QThread::currentThreadId();

    setlogmask (LOG_UPTO (LOG_DEBUG));

    openlog ("mere-about", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);

//    syslog (LOG_NOTICE, "Program started by User %d", "iklash");
    syslog (LOG_DEBUG, "A tree falls in a forest");

    closelog ();

    return true;
}
