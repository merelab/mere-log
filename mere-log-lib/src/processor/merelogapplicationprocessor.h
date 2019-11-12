#ifndef MERELOGAPPPROCESSOR_H
#define MERELOGAPPPROCESSOR_H

#include "merelogprocessor.h"

class MereLogApplicationProcessor : public MereLogProcessor
{
public:
    MereLogApplicationProcessor();

    static QString Field;
    QString field() const;

    bool process(MereLog *log);
};

#endif // MERELOGAPPPROCESSOR_H
