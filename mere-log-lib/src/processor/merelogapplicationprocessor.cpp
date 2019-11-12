#include "merelogapplicationprocessor.h"

#include <QCoreApplication>

QString MereLogApplicationProcessor::Field = "application";
MereLogApplicationProcessor::MereLogApplicationProcessor()
{

}

QString MereLogApplicationProcessor::field() const
{
    return MereLogApplicationProcessor::Field;
}

bool MereLogApplicationProcessor::process(MereLog *log)
{
    qDebug() << "Processing " << MereLogApplicationProcessor::Field;

    log->set(MereLogApplicationProcessor::Field, QVariant(qApp->applicationName()));

    return true;
}
\
