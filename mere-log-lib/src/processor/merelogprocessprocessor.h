#ifndef MERELOGPROCESSPROCESSOR_H
#define MERELOGPROCESSPROCESSOR_H

#include "merelogprocessor.h"

#include <QProcess>
#include <QCoreApplication>

class MereLogProcessProcessor : public MereLogProcessor
{
public:
    static QString Field;
    static QStringList Fields;
    QString field() const;

    bool process(MereLog *log);
};

#endif // MERELOGPROCESSPROCESSOR_H
