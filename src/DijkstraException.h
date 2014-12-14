/* 
 * File:   DijkstraException.h
 * Author: isen
 *
 * Created on 2 mai 2011, 16:40
 */

#ifndef DIJKSTRAEXCEPTION_H
#define	DIJKSTRAEXCEPTION_H

#include "MyException.h"

class DijkstraException : virtual public MyException {
public:
    DijkstraException();
    virtual QString what() = 0;
    virtual MyException* cloneExc() const = 0;
};

class NodeNotFoundException : virtual public DijkstraException {
private:
    int id;
public:
    NodeNotFoundException(QString description, int id);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

class PathNotFoundException : virtual public DijkstraException {
private:
    int id1;
    int id2;
public:
    PathNotFoundException(QString description, int id1, int id2);
    virtual QString what();
    virtual MyException* cloneExc() const;
};


#endif	/* DIJKSTRAEXCEPTION_H */

