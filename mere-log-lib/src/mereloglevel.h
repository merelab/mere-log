#ifndef MERELOGLEVEL_H
#define MERELOGLEVEL_H

#include "merelogglobal.h"

#include <QObject>

class MERE_LOG_LIBSPEC MereLogLevel : public QObject
{
    Q_OBJECT
public:
    explicit MereLogLevel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MERELOGLEVEL_H
