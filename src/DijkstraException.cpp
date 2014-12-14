#include "DijkstraException.h"

DijkstraException::DijkstraException() {

}

QString DijkstraException::what() {
    return MyException::what() + "### Dijkstra Exception ###" + "\n";
}

NodeNotFoundException::NodeNotFoundException(QString description, int id) : MyException(description) {
    this->id = id;
}

QString NodeNotFoundException::what() {
    return DijkstraException::what() + "The node with id '" + QString::number(this->id) + "' does not exist" + "\n";
}

MyException* NodeNotFoundException::cloneExc() const {
    return new NodeNotFoundException(*this);
}

PathNotFoundException::PathNotFoundException(QString description, int id1, int id2) : MyException(description) {
    this->id1 = id1;
    this->id2 = id2;
}

QString PathNotFoundException::what() {
    return DijkstraException::what() + "Can't find a path between nodes '" + QString::number(this->id1) + "' and '" + QString::number(this->id2) + "'" + "\n";
}

MyException* PathNotFoundException::cloneExc() const {
    return new PathNotFoundException(*this);
}