#include "mereloghandler.h"

MereLogHandler::MereLogHandler(MereLogConfig *config, QObject *parent)
    : QObject(parent),
      m_config(config)
{

}
