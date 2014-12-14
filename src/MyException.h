/* 
 * File:   MY_EXCEPTION.h
 * Author: isen
 *
 * Created on 20 janvier 2011, 14:31
 */

#ifndef MY_EXCEPTION_H
#define	MY_EXCEPTION_H

#include "utils.h"

class MyException {
protected:
    QString description;
    MyException* parentExc;
    QList<QString> out;
public:
    MyException(QString description = "", MyException* parentExc = NULL);
    virtual ~MyException();
    virtual QString what() = 0;

    virtual MyException* cloneExc() const = 0;

    QString getDescription() { return description; };

};

#endif	/* MY_EXCEPTION_H */

