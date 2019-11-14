#include "merelogsyslogformatter.h"

MereLogSyslogFormatter::MereLogSyslogFormatter(MereLogConfig *config)
    : MereLogFormatter(config)
{
    m_format = "${uuid} ${what} ${when} ${hostname} ${username} ${application} ${note} ${process-id} ${process-name} ${process-path}";
}

QString MereLogSyslogFormatter::format(MereLog *log)
{
    QString format = m_format;

    QRegExp rx;
    rx.setPattern("(\\$\\{([a-zA-Z1-9-\\.]+)\\})+");

    while(rx.indexIn(format) != -1)
    {
        QString match = rx.cap(1);
        QString field = match;
        field = field.remove("${").remove("}");

        QVariant value = log->get(field);

        format = format.replace(match, value.toString());
    }

    return format;
}

