#include "merelogfactory.h"
#include "meredefaultlogger.h"
#include "filter/merelogdefaultfilter.h"

//static
MereLogger* MereLogFactory::logger()
{
    MereLogConfig *config = new MereLogConfig();
    MereDefaultLogger *logger = new MereDefaultLogger(config);

//    MereLogDefaultFilter *filter = new MereLogDefaultFilter();
//    logger->addFilter(filter);

//    logger->addProcessor();


    return logger;
}
