#ifndef MERELOGPROCESSOR_H
#define MERELOGPROCESSOR_H

#include "../merelog.h"

class MereLogProcessor
{
public:
    static QString ProcessorCode;
    virtual QString field() const = 0;
    virtual bool process(MereLog *log) = 0;
};

#endif // MERELOGPROCESSOR_H
