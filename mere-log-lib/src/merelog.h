#ifndef MERELOG_H
#define MERELOG_H

#include "merelogglobal.h"

#include <QDateTime>
#include <QUuid>
#include <QMap>

class MERE_LOG_LIBSPEC MereLog
{
public:
    enum Severity
    {
        None            = 0,
        Emergency       = 1,
        Alert           = 1 << 1,
        Critical        = 1 << 2,
        Error           = 1 << 3,
        Warning         = 1 << 4,
        Notice          = 1 << 5,
        Informational   = 1 << 6,
        Debug           = 1 << 7,
        All             = 0b11111111
    } ;
    //Q_ENUM(Severity)

    ~MereLog();
    MereLog(Severity severity, QString message);

    QUuid     uuid() const;
    QDateTime when() const;
    Severity  what() const;
    QString   note() const;

    QVariant get(const QString &field) const;
    void set(const QString &field, const QVariant &value);

private:
    QUuid     m_uuid;
    QDateTime m_when;
    Severity  m_what;
    QString   m_note;

    QMap<QString, QVariant> m_fields;
};
Q_DECLARE_METATYPE(MereLog::Severity)
#endif // MERELOG_H
