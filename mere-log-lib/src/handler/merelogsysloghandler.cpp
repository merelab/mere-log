#include "merelogsysloghandler.h"
#include "../format/merelogdefaultformatter.h"

MereLogSyslogHandler::MereLogSyslogHandler(MereLogConfig *config)
    : MereLogHandler(config)
{

}

bool MereLogSyslogHandler::handle(MereLog *log)
{
    qDebug() << "Yes, please dump to the syslog!" << log->get("hostname");

    QString format = "${uuid} ${severity} ${timestamp} ${hostname} ${application} ${message}";

    MereLogDefaultFormatter fomatter(m_config);

    qDebug() << "1..." << format;
    qDebug() << "2..." << fomatter.format(log);

    return true;
}
