#ifndef MERELOGFACTORY_H
#define MERELOGFACTORY_H

#include "merelogger.h"

#include <QObject>

class MERE_LOG_LIBSPEC MereLogFactory : public QObject
{
    Q_OBJECT
private:
    MereLogFactory(){}

public:
    static MereLogger* logger();
};

#endif // MERELOGFACTORY_H
