#ifndef MERELOGCONFIG_H
#define MERELOGCONFIG_H

#include "merelogglobal.h"

#include <QObject>

class MERE_LOG_LIBSPEC MereLogConfig : public QObject
{
    Q_OBJECT
public:
    explicit MereLogConfig(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MERELOGCONFIG_H
