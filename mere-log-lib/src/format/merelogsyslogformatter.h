#ifndef MERELOGSYSLOGFORMATTER_H
#define MERELOGSYSLOGFORMATTER_H

#include "merelogformatter.h"

class MereLogSyslogFormatter : public MereLogFormatter
{
public:
    MereLogSyslogFormatter(MereLogConfig *config = nullptr);
    QString format(MereLog *log) override;

private:
    QString m_format;
};

#endif // MERELOGSYSLOGFORMATTER_H
