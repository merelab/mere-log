#include "merelog.h"

MereLog::MereLog(Severity severity, QString message)
    : m_uuid(QUuid::createUuid()),
      m_when(QDateTime::currentDateTime()),
      m_what(severity),
      m_note(message)
{
    set("uuid"     , m_uuid);
    set("when"     , m_when);
    set("what"     , m_what);
    set("note"     , m_note);
}

QUuid MereLog::uuid() const
{
    return m_uuid;
}

QDateTime MereLog::when() const
{
    return m_when;
}

MereLog::Severity MereLog::what() const
{
    return m_what;
}

QString MereLog::note() const
{
    return m_note;
}

QVariant MereLog::get(const QString &field) const
{
    return m_fields.value(field);
}

void MereLog::set(const QString &field, const QVariant &value)
{
    m_fields.insert(field, value);
}
