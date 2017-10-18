#ifndef ERROR_H
#define ERROR_H

#include <QString>
#include <QMessageBox>

class error : public QDialog
{
    public:
        error();
};

class warningerror : public error
{
public:
    warningerror(QString title, QString description);
};

class informationerror : public error
{
public:
    informationerror(QString title, QString description);
};

class criticalerror : public error
{
public:
    criticalerror(QString title, QString description);
};

#endif // ERROR_H
