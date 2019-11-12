#include "merelogger.h"

MereLogger::MereLogger(MereLogConfig *config)
    : m_config(config)
{

}

MereLogConfig* MereLogger::config() const
{
    return m_config;
}
