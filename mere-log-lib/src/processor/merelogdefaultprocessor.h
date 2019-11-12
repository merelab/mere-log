#ifndef MERELOGDEFAULTPROCESSOR_H
#define MERELOGDEFAULTPROCESSOR_H

#include <QObject>

class MereLogDefaultProcessor : public QObject
{
    Q_OBJECT
public:
    explicit MereLogDefaultProcessor(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MERELOGDEFAULTPROCESSOR_H
