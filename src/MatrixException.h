/* 
 * File:   MatrixException.h
 * Author: isen
 *
 * Created on 20 janvier 2011, 14:32
 */

#ifndef MATRIXEXCEPTION_H
#define	MATRIXEXCEPTION_H

#include "MyException.h"

class MatrixException : virtual public MyException {
private:
public:
    MatrixException();
    virtual QString what() = 0;
    virtual MyException* cloneExc() const = 0;
};

class OutOfRange : virtual public MatrixException {
private:
    int entry;
    int rangeMax;
public:
    OutOfRange(int entry, int rangeMax);
    virtual QString what() = 0;
    virtual MyException* cloneExc() const = 0;
};

class RowOutOfRange : virtual public OutOfRange {
public:
    RowOutOfRange(QString description, int entry, int rangeMax);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

class ColOutOfRange : virtual public OutOfRange {
public:
    ColOutOfRange(QString description, int entry, int rangeMax);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

class NegativeSize : virtual public MatrixException {
public:
    virtual QString what() = 0;
    virtual MyException* cloneExc() const = 0;
};

class NegativeRow : virtual public NegativeSize {
public:
    NegativeRow(QString description);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

class NegativeCol : virtual public NegativeSize {
public:
    NegativeCol(QString description);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

#endif	/* MATRIXEXCEPTION_H */

