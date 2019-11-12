#include "merelogcontext.h"

QString MereLogContext::hostname() const
{
    return m_hostame;
}

void MereLogContext::setHostname(const QString &hostname)
{
    m_hostame = hostname;
}

QString MereLogContext::uname() const
{
    return m_uname;
}

void MereLogContext::setUname(const QString &uname)
{
    m_uname = uname;
}


int MereLogContext::process() const
{
    return m_process;
}

void MereLogContext::setProcess(const int &process)
{
    m_process = process;
}

QString MereLogContext::program() const
{
    return m_program;
}

void MereLogContext::setProgram(const QString &program)
{
    m_program = program;
}

QString MereLogContext::file() const
{
    return m_file;
}

void MereLogContext::setFile(const QString &file)
{
    m_file = file;
}

QString MereLogContext::procedure() const
{
    return m_procedure;
}

void MereLogContext::setProcedure(const QString &procedure)
{
    m_procedure = procedure;
}

int MereLogContext::line() const
{
    return m_line;
}

void MereLogContext::setLine(const int &line)
{
    m_line = line;
}

