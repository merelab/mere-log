#ifndef MERELOG_H
#define MERELOG_H

#include "merelogglobal.h"

#include <QObject>

class MERE_LOG_LIBSPEC MereLog : public QObject
{
    Q_OBJECT
public:
    explicit MereLog(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MERELOG_H
