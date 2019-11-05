#ifndef MERELOGGER_H
#define MERELOGGER_H

#include "merelogglobal.h"

#include <QObject>

class MERE_LOG_LIBSPEC MereLogger : public QObject
{
    Q_OBJECT
public:
    explicit MereLogger(QObject *parent = nullptr);
    void log(const QString &message){}
    void log(const QString &priority, const QString &message){}

signals:

public slots:
};

#endif // MERELOGGER_H
