#ifndef MERELOGFORMATTER_H
#define MERELOGFORMATTER_H

#include "../merelog.h"
#include "../merelogconfig.h"

class MereLogFormatter
{
public:
    explicit MereLogFormatter(MereLogConfig *config = nullptr);

    virtual QString format(MereLog *log) = 0;

protected:
    MereLogConfig *m_config;

};

#endif // MERELOGFORMATTER_H
