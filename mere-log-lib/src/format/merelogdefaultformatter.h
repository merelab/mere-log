#ifndef MERELOGDEFAULTFORMATTER_H
#define MERELOGDEFAULTFORMATTER_H

#include "merelogformatter.h"
#include "../merelogconfig.h"

#include <QDebug>

class MereLogDefaultFormatter : public MereLogFormatter
{
public:
    MereLogDefaultFormatter(MereLogConfig *config = nullptr);

    QString format(MereLog *log) override;

private:
    QString m_format;
};

#endif // MERELOGDEFAULTFORMATTER_H
