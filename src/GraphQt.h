/*
 * File:   GraphQt.h
 * Author: isen
 *
 * Created on 22 mars 2011, 11:25
 */

#ifndef GRAPHQT_H
#define	GRAPHQT_H

#include "utils.h"
#include "Graph.h"

/* Class GraphList, inherit from Graph
 * ----------------------------------------
 * An addon of the class graph, which add a name and a lastUpdate time to a normal graph
 * ----------------------------------------
 */
template<typename T> class GraphQt : public Graph<T> {
    /* PRIVATE VARIABLES
     * @name = The name of the Graph
     * @lastUpdate = The last use of the graph
     * */
private:
    QString name;
    QDateTime lastUpdate;
public:
    /* CONSTRUCTOR */
    GraphQt(bool oriented, bool weighted, QString name = "");

    /* SETTERS & GETTERS */
    void setName(QString name) { this->name = name; };
    QString getName() { return name; };

    void setDate(QDateTime date) { this->lastUpdate = date; };
    QDateTime getDate() { return lastUpdate; };
};

template<typename T> GraphQt<T>::GraphQt(bool oriented, bool weighted, QString name) : Graph<T>(oriented, weighted) {
    this->setName(name);
    this->setDate(QDateTime::currentDateTime());
}


#endif	/* GRAPHQT_H */

