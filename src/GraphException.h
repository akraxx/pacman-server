/* 
 * File:   GraphException.h
 * Author: robin
 *
 * Created on 18 mars 2011, 09:19
 */

#ifndef GraphEXCEPTION_H
#define	GraphEXCEPTION_H

#include "MyException.h"

class GraphException : virtual public MyException {
private:
public:
    GraphException();
    virtual QString what() = 0;
    virtual MyException* cloneExc() const = 0;
};

class NotWeightedGraphException : virtual public GraphException {
public:
    NotWeightedGraphException(QString description);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

class NodeException : virtual public GraphException {
private:
    int entry;
public:
    NodeException(int entry);
    virtual QString what() = 0;
    virtual MyException* cloneExc() const = 0;
};


class UndefinedNodeException : virtual public NodeException {
public:
    UndefinedNodeException(QString description, int entry, MyException* parentExc = NULL);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

class NotFoundNodeException : virtual public NodeException {
public:
    NotFoundNodeException(QString description, int entry);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

class ExistNodeException : virtual public NodeException {
public:
    ExistNodeException(QString description, int entry);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

class InvalidIdNodeException : virtual public NodeException {
public:
    InvalidIdNodeException(QString description, int entry);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

class NeighboorNotFoundNodeException : virtual public NodeException {
private:
    int idk;
public:
    NeighboorNotFoundNodeException(QString description, int entry, int idk, MyException* parentExc = NULL);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

class EdgeException : virtual public GraphException {
protected:
    int id1;
    int id2;
public:
    EdgeException(int id1, int id2);
    virtual QString what() = 0;
    virtual MyException* cloneExc() const = 0;
};

class UndefinedEdgeException : virtual public EdgeException {
public:
    UndefinedEdgeException(QString description, int id1, int id2, MyException* parentExc = NULL);
    UndefinedEdgeException(const UndefinedEdgeException& source);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

class NotFoundEdgeException : virtual public EdgeException {
public:
    NotFoundEdgeException(QString description, int id1, int id2, MyException* parentExc = NULL);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

class ExistEdgeException : virtual public EdgeException {
public:
    ExistEdgeException(QString description, int id1, int id2);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

class GraphListException : virtual public MyException {
public:
    GraphListException();
    virtual QString what() = 0;
    virtual MyException* cloneExc() const = 0;
};

class GraphNotFoundInListException : virtual public GraphListException {
private:
    int id;
public:
    GraphNotFoundInListException(QString description, int id);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

class GraphParserException : virtual public MyException {
public:
    GraphParserException();
    virtual QString what() = 0;
    virtual MyException* cloneExc() const = 0;
};

class MissingArgumentGraphParserException : virtual public GraphParserException {
private:
    QString arg;
public:
    MissingArgumentGraphParserException(QString description, QString arg);
    virtual QString what();
    virtual MyException* cloneExc() const;
};

#endif	/* GraphEXCEPTION_H */

