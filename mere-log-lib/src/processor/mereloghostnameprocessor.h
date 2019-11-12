#ifndef MERELOGHOSTPROCESSOR_H
#define MERELOGHOSTPROCESSOR_H

#include "merelogprocessor.h"

class MereLogHostnameProcessor : public MereLogProcessor
{
public:
    MereLogHostnameProcessor();

    static QString Field;
    QString field() const override;

    bool process(MereLog *log) override;
};

#endif // MERELOGHOSTPROCESSOR_H
