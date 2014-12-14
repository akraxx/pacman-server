#include "GraphList.h"

GraphList::GraphList() {
    this->lastInsert = 0;
}

GraphList::~GraphList() {
    /* DELETE ALL THE GRAPH FROM THE MEMORY */
    QHashIterator<int, GraphQt<DEFAULT_TYPEVAL>*> i(this->graphs);
    while (i.hasNext()) {
        i.next();
        delete i.value();
    }
}

void GraphList::deleteObsoleteGraphs(int keepalive) {
    QHashIterator<int, GraphQt<DEFAULT_TYPEVAL>*> i(this->graphs);
    while (i.hasNext()) {
        i.next();
        QDateTime futureTime = i.value()->getDate().addSecs(60 * keepalive);
        /* IF THE GRAPH IS OBSOLETE WE DELETE IT */
        if(futureTime < QDateTime::currentDateTime())
            this->deleteGraph(i.key());
    }
}

bool GraphList::GraphExists(int id) {
    return this->graphs.contains(id);
}

GraphQt<DEFAULT_TYPEVAL>* GraphList::getGraph(int id) {
    if(this->GraphExists(id)) {
        /* UPDATE THE LAST UPDATE TIME */
        this->graphs.value(id)->setDate(QDateTime::currentDateTime());
        return this->graphs[id];
    }
    else
        throw GraphNotFoundInListException("Can't get this graph", id);
}

void GraphList::addGraph(GraphQt<DEFAULT_TYPEVAL>* graph) {
    this->graphs.insert(this->lastInsert+1, graph);
    this->lastInsert++;

    /* IF NO NAME HAS BEEN SENT, WE DEFINE A GENERIC NAME */
    if(this->graphs.value(this->lastInsert)->getName().isEmpty())
        this->graphs.value(this->lastInsert)->setName("graph-"+QString::number(this->lastInsert));
}

void GraphList::deleteGraph(int id) {
    if(this->GraphExists(id)) {
        delete this->graphs.value(id);
        this->graphs.remove(id);
    }
    else
        throw GraphNotFoundInListException("Can't get this graph", id);
}

void GraphList::editGraph(int id, GraphQt<DEFAULT_TYPEVAL>* graph) {
    if(this->GraphExists(id)) {
        this->graphs.remove(id);
        this->graphs.insert(id, graph);
        /* UPDATE THE LAST UPDATE TIME */
        this->graphs.value(id)->setDate(QDateTime::currentDateTime());
    }
    else
        throw GraphNotFoundInListException("Can't edit this graph", id);
}