#include "merelogprocessprocessor.h"


QString MereLogProcessProcessor::Field = "process-id";
QStringList MereLogProcessProcessor::Fields = {"process-id", "process-name", "process-path"};
QString MereLogProcessProcessor::field() const
{
    return MereLogProcessProcessor::Field;
}

bool MereLogProcessProcessor::process(MereLog *log)
{
    qDebug() << "Processing " << MereLogProcessProcessor::Field;

    log->set("process-id", QVariant(QCoreApplication::applicationPid()));
    log->set("process-name", QVariant(QCoreApplication::applicationName()));
    log->set("process-path", QVariant(QCoreApplication::applicationFilePath()));

    return true;
}
\
