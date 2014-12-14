#include "GraphException.h"


GraphException::GraphException() {

}

QString GraphException::what() {
    return MyException::what() + "### Graph Exception ###" + "\n";
}

NotWeightedGraphException::NotWeightedGraphException(QString description) : MyException(description) {

}

QString NotWeightedGraphException::what() {
    return GraphException::what() + "Graph is not weighted";
}

MyException* NotWeightedGraphException::cloneExc() const {
    return new NotWeightedGraphException(*this);
}
NodeException::NodeException(int entry) {
    this->entry = entry;
}

QString NodeException::what() {
    return GraphException::what() +
            "Node exception :" + "\n" +
            "\tYour entry : node = " + QString::number(this->entry) + "\n";
}

UndefinedNodeException::UndefinedNodeException(QString description, int entry, MyException* parentExc) : MyException(description, parentExc), NodeException(entry) {

}

QString UndefinedNodeException::what() {
    return NodeException::what();
}

MyException* UndefinedNodeException::cloneExc() const {
    return new UndefinedNodeException(*this);
}

NotFoundNodeException::NotFoundNodeException(QString description, int entry) : MyException(description), NodeException(entry) {

}

QString NotFoundNodeException::what() {
    return NodeException::what() + "Can't find a node with this id" + "\n";
}

MyException* NotFoundNodeException::cloneExc() const {
    return new NotFoundNodeException(*this);
}

ExistNodeException::ExistNodeException(QString description, int entry) : MyException(description), NodeException(entry) {

}

QString ExistNodeException::what() {
    return NodeException::what() + "A node with this id already exists" + "\n";
}

MyException* ExistNodeException::cloneExc() const {
    return new ExistNodeException(*this);
}

InvalidIdNodeException::InvalidIdNodeException(QString description, int entry) : MyException(description), NodeException(entry) {
    
}

QString InvalidIdNodeException::what() {
    return NodeException::what() + "Node id must be a positive integer" + "\n";
}

MyException* InvalidIdNodeException::cloneExc() const {
    return new InvalidIdNodeException(*this);
}

NeighboorNotFoundNodeException::NeighboorNotFoundNodeException(QString description, int entry, int idk, MyException* parentExc) : MyException(description, parentExc), NodeException(entry) {
    this->idk = idk;
}

QString NeighboorNotFoundNodeException::what() {
    return NodeException::what() + "Can't find the neighboor with idk : " + QString::number(this->idk) + "\n";
}

MyException* NeighboorNotFoundNodeException::cloneExc() const {
    return new NeighboorNotFoundNodeException(*this);
}

EdgeException::EdgeException(int id1, int id2) {
    this->id1 = id1;
    this->id2 = id2;
}

QString EdgeException::what() {
    return GraphException::what() +
            "Edge exception\n" +
            "\tYour entry : first-node = " + QString::number(this->id1) + " , second-node = " + QString::number(this->id2) + "\n";
}

UndefinedEdgeException::UndefinedEdgeException(QString description, int id1, int id2, MyException* parentExc) : MyException(description, parentExc), EdgeException(id1, id2) {

}

UndefinedEdgeException::UndefinedEdgeException(const UndefinedEdgeException& source) : MyException(source.description), EdgeException(source.id1, source.id2) {
    if(source.parentExc != NULL)
        this->parentExc = source.parentExc->cloneExc();
}

QString UndefinedEdgeException::what() {
    return EdgeException::what();
}

MyException* UndefinedEdgeException::cloneExc() const {
    return new UndefinedEdgeException(*this);
}

NotFoundEdgeException::NotFoundEdgeException(QString description, int id1, int id2, MyException* parentExc) : MyException(description, parentExc), EdgeException(id1, id2) {

}

QString NotFoundEdgeException::what() {
    return EdgeException::what() + "Can't find an edge between this nodes\n";
}

MyException* NotFoundEdgeException::cloneExc() const {
    return new NotFoundEdgeException(*this);
}

ExistEdgeException::ExistEdgeException(QString description, int id1, int id2) : MyException(description), EdgeException(id1, id2) {

}

QString ExistEdgeException::what() {
    return EdgeException::what() + "An edge between this nodes already exists\n";
}

MyException* ExistEdgeException::cloneExc() const {
    return new ExistEdgeException(*this);
}

GraphListException::GraphListException() {

}

QString GraphListException::what() {
    return MyException::what() + "### GraphList Exception ###\n";
}

GraphNotFoundInListException::GraphNotFoundInListException(QString description, int id) : MyException(description) {
    this->id = id;
}

QString GraphNotFoundInListException::what() {
    return GraphListException::what() + "Can't find the graph with id : " + this->id + "\n";
}

MyException* GraphNotFoundInListException::cloneExc() const {
    return new GraphNotFoundInListException(*this);
}

GraphParserException::GraphParserException() {

}

QString GraphParserException::what() {
    return MyException::what() + "### GraphParser Exception ###\n";
}

MissingArgumentGraphParserException::MissingArgumentGraphParserException(QString description, QString arg) : MyException(description) {
    this->arg = arg;
}

QString MissingArgumentGraphParserException::what() {
    return GraphParserException::what() + "Can't parse because the argument \" " + this->arg + " \" is missing\n";
}

MyException* MissingArgumentGraphParserException::cloneExc() const {
    return new MissingArgumentGraphParserException(*this);
}