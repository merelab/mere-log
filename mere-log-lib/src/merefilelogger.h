#ifndef MEREFILELOGGER_H
#define MEREFILELOGGER_H

#include "merelogger.h"

class MERE_LOG_LIBSPEC MereFileLogger : public MereLogger
{
//    Q_OBJECT
public:
//    explicit MereFileLogger(QObject *parent = nullptr);

    bool error(const QString &message){return true;}
    bool warn(const QString &message) {return true;}
    bool info(const QString &message) {return true;}
    bool debug(const QString &message){return true;}
    bool trace(const QString &message){return true;}

signals:

public slots:
};

#endif // MEREFILELOGGER_H
