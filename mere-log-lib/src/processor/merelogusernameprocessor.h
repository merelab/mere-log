#ifndef MERELOGUSERNAMEPROCESSOR_H
#define MERELOGUSERNAMEPROCESSOR_H

#include "merelogprocessor.h"

class MereLogUsernameProcessor : public MereLogProcessor
{
public:
    static QString Field;
    QString field() const;

    bool process(MereLog *log);
};

#endif // MERELOGUSERNAMEPROCESSOR_H
