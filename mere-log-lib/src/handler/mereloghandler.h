#ifndef MERELOGHANDLER_H
#define MERELOGHANDLER_H

#include "../merelog.h"
#include "../merelogconfig.h"

#include <QObject>

class MereLogHandler : public QObject
{
    Q_OBJECT
public:
    explicit MereLogHandler(MereLogConfig *config, QObject *parent = nullptr);

signals:

public slots:
    virtual bool handle(MereLog *log) = 0;

protected:
    MereLogConfig *m_config;
};

#endif // MERELOGHANDLER_H
