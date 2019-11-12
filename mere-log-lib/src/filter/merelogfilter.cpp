#include "merelogfilter.h"
#include "../merelogconfig.h"

MereLogFilter::MereLogFilter(MereLogConfig *config)
    : m_config(config)
{

}

MereLogConfig* MereLogFilter::config() const
{
    return m_config;
}
