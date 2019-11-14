#include "merelogusernameprocessor.h"


QString MereLogUsernameProcessor::Field = "username";
QString MereLogUsernameProcessor::field() const
{
    return MereLogUsernameProcessor::Field;
}

bool MereLogUsernameProcessor::process(MereLog *log)
{
    qDebug() << "Processing " << MereLogUsernameProcessor::Field;

    log->set(MereLogUsernameProcessor::Field, QVariant(getenv("USER")));

    return true;
}
