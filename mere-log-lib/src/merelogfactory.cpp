#include "merelogfactory.h"

#include "merelogconfig.h"
#include "meredefaultlogger.h"

//static
MereLogger* MereLogFactory::logger()
{
    MereLogConfig *config = new MereLogConfig();
    MereDefaultLogger *logger = new MereDefaultLogger(config);
    return logger;
}
