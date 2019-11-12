#ifndef MERELOGFACTORY_H
#define MERELOGFACTORY_H

#include "merelogglobal.h"
#include "merelogger.h"

class MERE_LOG_LIBSPEC MereLogFactory
{
public:
    static MereLogger* logger();

private:
    MereLogFactory(){}
};

#endif // MERELOGFACTORY_H
