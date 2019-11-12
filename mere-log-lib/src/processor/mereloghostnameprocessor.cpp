#include "mereloghostnameprocessor.h"

#include <QSysInfo>

QString MereLogHostnameProcessor::Field = "hostname";
MereLogHostnameProcessor::MereLogHostnameProcessor()
{

}

QString MereLogHostnameProcessor::field() const
{
    return MereLogHostnameProcessor::Field;
}

bool MereLogHostnameProcessor::process(MereLog *log)
{
    qDebug() << "Processing " << MereLogHostnameProcessor::Field;

    log->set(MereLogHostnameProcessor::Field, QVariant(QSysInfo::machineHostName()));

    return true;
}
\
