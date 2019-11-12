#ifndef MERELOGCONTEXT_H
#define MERELOGCONTEXT_H

#include <QString>

class MereLogContext
{
public:
    QString hostname() const;
    void setHostname(const QString &hostname);

    QString uname() const;
    void setUname(const QString &uname);

    int process() const;
    void setProcess(const int &process);

    QString program() const;
    void setProgram(const QString &program);

    QString file() const;
    void setFile(const QString &file);

    QString procedure() const;
    void setProcedure(const QString &procedure);

    int line() const;
    void setLine(const int &line);

private:
    QString m_hostame;
    QString m_uname;
    int m_process;
    QString m_program;
    QString m_file;
    QString m_procedure;
    int m_line;
};

#endif // MERELOGCONTEXT_H
