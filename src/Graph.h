/*
 * File:   Graph.h
 * Author: robin
 *
 * Created on 17 février 2011, 10:29
 */

#ifndef Graph_H
#define	Graph_H

#include "utils.h"
#include "Matrix.h"
#include "GraphException.h"

template<typename T> class GraphNode {
private:
    int id;
    T value;
    QList<int> neighbors;
public:
    GraphNode(int id, T value);
    ~GraphNode();

    void setId(int id) { this->id = id; };
    void setValue(T value) { this->value = value; };

    int getId() { return this->id; };
    T getValue() { return this->value; };
    QList<int> getNeighbors() { return this->neighbors; };

    void addNeighbor(int id);
};

template<typename T> GraphNode<T>::GraphNode(int id, T value) {
    this->setId(id);
    this->setValue(value);
}

template<typename T> GraphNode<T>::~GraphNode() {

}


template<typename T> void GraphNode<T>::addNeighbor(int id) {
    this->neighbors.append(id);
}

template<typename T> class Graph {
private:
    bool oriented;
    bool weighted;
    Matrix<GraphNode<int>* > nodes;
    Matrix<T> edges;
    //QHash<int, <QList<int> > neighbors;
    int codeEdgeExist;
    int codeEdgeInexistent;

    void checkNodesId(int id1, int id2);
    //int searchNode(int id);
    int searchPred(int id);
public:
    Graph(bool oriented, bool weighted);
    ~Graph();

    void setWeighted(bool weighted) { this->weighted = weighted; }
    bool isWeighted() const { return weighted; }
    void setOriented(bool oriented) { this->oriented = oriented; }
    bool isOriented() const { return oriented; }
    int searchNode(int id);
    int getOrder();

    bool nodeExists(int id);

    int getIdByIndex(int id);

    T getNodeValue(int id);
    void setNodeValue(int id, T value);
    void setNodesValues(T value);

    bool edgeExists(int id1, int id2);
    bool edgeExistsByIndex(int id1, int id2);
    T getEdgeValue(int id1, int id2);
    void setEdgeValue(int id1, int id2, T value);
    void setEdgesValues(T value);

    int getNeighborhoodsize(int id);
    int getNeighbor(int id, int idx);
    QList<int> getNeighbors(int id);

    void addNode(int id);
    void removeNode(int id);
    void addEdge(int id1, int id2);
    void removeEdge(int id1, int id2);

    void printGraph();
    QDomDocument formattedHtmlGraph();
};

template<typename T> void Graph<T>::checkNodesId(int id1, int id2) {
    searchNode(id1);
    searchNode(id2);
}

template<typename T> Graph<T>::Graph(bool oriented, bool weighted) : nodes(1,0,NULL), edges(0,0,UNDEFINED_VALUE) {
    this->setWeighted(weighted);
    this->setOriented(oriented);

    this->codeEdgeExist = EDGE_EXIST;
    this->codeEdgeInexistent = UNDEFINED_VALUE;
}

template<typename T> Graph<T>::~Graph() {
    int cols = nodes.getColumns();
    for(int i = 1; i <= cols; i++)
        delete nodes.getValue(1, i);
}

template<typename T> int Graph<T>::getOrder() {
     return this->nodes.getColumns();
}

template<typename T> int Graph<T>::searchNode(int id) {

    int mil = 1;
    int begin = 1;
    int end;
    bool find = false;

    if (id > 0) {

        timeval start;
        gettimeofday(&start, NULL);
        end = nodes.getColumns();

        if(end != 0) {
            if(id > nodes.getValue(1,end)->getId())
                throw NotFoundNodeException("Can't find this node", id);
            else if (id > nodes.getValue(1,begin)->getId()){
                while (begin <= end && !find) {
                    mil = begin + (end - begin) / 2;
                    
                    if(id == nodes.getValue(1,mil)->getId())
                        find = true;
                    else if (id > nodes.getValue(1,mil)->getId())
                        begin = mil + 1;
                    else
                        end = mil - 1;
                }
            }
//            if(id == nodes.getValue(1,end)->getId())
//                return end-1;
//            else if(id == nodes.getValue(1,begin)->getId())
//                return begin;
//            else if (id > nodes.getValue(1,begin)->getId() && id < nodes.getValue(1,end)->getId()) {
//                while (!find && begin <= end) {
//                    mil = begin + (end - begin) / 2;
//                    if (id == nodes.getValue(1,mil)->getId())
//                        find = true;
//                    else {
//                        if(id > nodes.getValue(1, mil)->getId())
//                            begin = mil + 1;
//                        else
//                            end = mil - 1;
//                    }
//                }
//            }
        }

        timeval stop;
        gettimeofday(&stop, NULL);
        //qDebug("%u.%u", stop.tv_sec - start.tv_sec, stop.tv_usec - start.tv_usec);
        if (nodes.getValue(1, mil)->getId() == id)
            return mil;
        else
            throw NotFoundNodeException("Can't find this node", id);
    }
    else
        throw InvalidIdNodeException("Can't find this node", id);
}

template<typename T> int Graph<T>::searchPred(int id){
    int mil;
    int begin = 1;
    int end;

    end = nodes.getColumns();
    if(end != 0) {
        if(id >= nodes.getValue(1,end)->getId())
            return end;
        else if (id > nodes.getValue(1,begin)->getId()){
            while (begin <= end) {
                mil = begin + (end - begin) / 2;
                if (id > nodes.getValue(1,mil)->getId())
                    begin = mil + 1;
                else
                    end = mil - 1;
            }
            return end;
        }
    }
    return -1;
}

template<typename T> bool Graph<T>::nodeExists(int id) {
    try {
        searchNode(id);
    }
    catch(MyException &e) {
        return false;
    }
    return true;
}

template<typename T> int Graph<T>::getIdByIndex(int index) {
    return nodes.getValue(1, index)->getId();
}

template<typename T> T Graph<T>::getNodeValue(int id){
    try {
        return nodes.getValue(1,searchNode(id))->getValue();
    }
    catch(MyException& e) {
        throw UndefinedNodeException("Can't get a node value", id, e.cloneExc());
    }
}

template<typename T> void Graph<T>::setNodeValue(int id, T value){
    try {
        nodes.printMatrix();
        nodes.getValue(1,searchNode(id))->setValue(value);
    }
    catch(MyException& e) {
        throw UndefinedNodeException("Can't set a node value", id, e.cloneExc());
    }
}

template<typename T> void Graph<T>::setNodesValues(T value) {
    for (int j = 1; j <= nodes.getColumns(); j++)
        nodes.getValue(1,j)->setValue(value);
}

template<typename T> bool Graph<T>::edgeExistsByIndex(int index1, int index2){
    try {
        if(edges.getValue(index1, index2) == this->codeEdgeInexistent)
            return false;
    }
    catch(MyException& e) {

        return false;
    }

    return true;
}

template<typename T> bool Graph<T>::edgeExists(int id1, int id2){
    try {
        if(edges.getValue(searchNode(id1), searchNode(id2)) == this->codeEdgeInexistent) 
            return false;
    }
    catch(MyException& e) {
        
        return false;
    }

    return true;
}

template<typename T> T Graph<T>::getEdgeValue(int id1, int id2){
    if(!this->weighted)
        throw NotWeightedGraphException("Can't get an edge value");

    int index1;
    int index2;
    try {
        index1 = searchNode(id1);
        index2 = searchNode(id2);
    }
    catch(MyException& e) {
        throw UndefinedEdgeException("Can't get an edge value", id1, id2, e.cloneExc());
    }

    if(this->edgeExistsByIndex(index1, index2))
        return edges.getValue(index1, index2);
    else
        throw NotFoundEdgeException("Can't get an edge value", id1, id2);
}

template<typename T> void Graph<T>::setEdgeValue(int id1, int id2, T value){
    if(!this->weighted)
        throw NotWeightedGraphException("Can't set an edge value");

    int index1;
    int index2;
    try {
        index1 = searchNode(id1);
        index2 = searchNode(id2);

    }
    catch(MyException& e) {
        throw UndefinedEdgeException("Can't set an edge value", id1, id2, e.cloneExc());
    }

    if(this->edgeExists(id1, id2)) {
        edges.setValue(index1, index2, value);

        if(!this->oriented) {
            edges.setValue(index2, index1, value);
        }
    }
    else
        throw NotFoundEdgeException("Can't set an edge value", id1, id2);
}

template<typename T> void Graph<T>::setEdgesValues(T value){
    if(!this->weighted)
        throw NotWeightedGraphException("Can't set edges values");
    int order = nodes.getColumns();

    for (int i = 1; i <= order; i++) {
        for (int j = 1; j <= order; j++) {
            if(edges.getValue(i,j) != this->codeEdgeInexistent)
                edges.setValue(i,j,value);
        }
    }
}

template<typename T> int Graph<T>::getNeighborhoodsize(int id){
    int size = 0;
    int order = edges.getColumns();
    int index;
    try {
        index = searchNode(id);
    }
    catch(MyException& e) {
        throw UndefinedNodeException("Can't get the neighborhoodsize", id, e.cloneExc());
    }

    for (int col = 1; col <= order; col++) {
        if (edges.getValue(index, col) != this->codeEdgeInexistent)
            size++;
    }

    return size;
}

template<typename T> int Graph<T>::getNeighbor(int id, int k){
    int size = 0;
    int col = 1;
    int order = edges.getColumns();
    int index;
    
    try {
        index = searchNode(id);
    }
    catch(MyException& e) {
        throw NeighboorNotFoundNodeException("Can't get a neighboor", id, k, e.cloneExc());
    }

    while (col <= order && size < k) {
        if (edges.getValue(searchNode(id), col) != this->codeEdgeInexistent)
            size++;

        col++;
    }

    if (k == size)
        return nodes.getValue(1,col-1)->getId();
    else
        throw NeighboorNotFoundNodeException("Can't find a neighboor", id, k);
}

template<typename T> QList<int> Graph<T>::getNeighbors(int id){

    int index;

    try {
        index = searchNode(id);
    }
    catch(MyException& e) {
        throw UndefinedNodeException("Can't get neighboors", id, e.cloneExc());
    }

    return nodes.getValue(1, index)->getNeighbors();
}

template<typename T> void Graph<T>::addNode(int id) {
    int pnode;

    if(id < 0)
        throw InvalidIdNodeException("Can't add a node", id);
    else if(this->nodeExists(id))
        throw ExistNodeException("Can't add a node", id);
    else {
        pnode = searchPred(id);
        GraphNode<int>* node = new GraphNode<int>(id, UNDEFINED_VALUE);
        if (pnode > 0) {
            nodes.addColumn(pnode+1);
            nodes.setValue(1,pnode+1,node);
            edges.addColumn(pnode+1);
            edges.addRow(pnode+1);
        } else {
            nodes.addColumn(1);
            nodes.setValue(1,1,node);
            edges.addRow(1);
            edges.addColumn(1);
        }
    };
}

template<typename T> void Graph<T>::removeNode(int id) {
    try {
        int index = searchNode(id);
        delete nodes.getValue(1, index);

        nodes.removeColumn(index);
        edges.removeColumn(index);
        edges.removeRow(index);
    }
    catch(MyException &e) {
        throw UndefinedNodeException("Can't remove a node", id, e.cloneExc());
    }
}

template<typename T> void Graph<T>::addEdge(int id1, int id2) {
    int index1;
    int index2;
    if(!this->weighted)
        throw NotWeightedGraphException("Can't add an edge");
    try {
        index1 = searchNode(id1);
        index2 = searchNode(id2);
    }
    catch(MyException &e) {
        throw UndefinedEdgeException("Can't add an edge", id1, id2, e.cloneExc());
    }

    if(!this->edgeExists(id1, id2)) {
        edges.setValue(index1, index2, this->codeEdgeExist);
        nodes.getValue(1,index1)->addNeighbor(id2);
        if(!this->oriented) {
            edges.setValue(index2, index1, this->codeEdgeExist);
            nodes.getValue(1,index2)->addNeighbor(id1);
        }
    }
    else
        throw ExistEdgeException("Can't add an edge", id1, id2);

}

template<typename T> void Graph<T>::removeEdge(int id1, int id2) {
    if(!this->weighted)
        throw NotWeightedGraphException("Can't remove an edge");

    try {
        setEdgeValue(id1, id2, this->codeEdgeInexistent);
    }
    catch(MyException &e) {
        throw UndefinedEdgeException("Can't remove an edge", id1, id2, e.cloneExc());
    }
}

template<typename T> void Graph<T>::printGraph() {
    cout << "\t######## Graph #########" << endl;

    cout << "\n\t######## NODES #########" << endl;
    nodes.printMatrix();

    cout << "\n\t######## EDGES #########" << endl;
    edges.printMatrix();

     cout << "> Oriented : " << oriented << endl;
    cout << "> Weighted : " << weighted << endl;


}

template<typename T> QDomDocument Graph<T>::formattedHtmlGraph() {
    QDomDocument doc;
    QDomElement elemFieldset = doc.createElement("fieldset");
    QDomElement elemLegend = doc.createElement("legend");

    QString titleLegend = "GRAPH, oriented = ";
    titleLegend.append((this->oriented) ? "true" : "false");
    titleLegend += ", weighted = ";
    titleLegend.append((this->weighted) ? "true" : "false");
    
    QDomText textLegend = doc.createTextNode(titleLegend);
    elemLegend.appendChild(textLegend);
    elemFieldset.appendChild(elemLegend);
    
    QDomElement elemTable = doc.createElement("table");
    int order = nodes.getColumns();
    for(int i = 1; i <= order; i++) {
        int id = this->getIdByIndex(i);
        QString s_id = QString::number(id);
        QDomElement elemLineNode = doc.createElement("tr");

        /* NODE COLUMN, WITH ID AND VALUE */
        QDomElement nodeCol = doc.createElement("td");
        QDomElement nodeElem = doc.createElement("span");

        nodeElem.setAttribute("class", "node");
        nodeElem.setAttribute("id", "node-"+s_id);
        
        QString textNode = "ID = " + s_id + " { VALUE = " + QString::number(this->getNodeValue(id)) + " }";
        QDomText textNodeElem = doc.createTextNode(textNode);
        nodeElem.appendChild(textNodeElem);
        nodeCol.appendChild(nodeElem);
        elemLineNode.appendChild(nodeCol);

        /* EDGES OF THIS NODE */
        QDomElement edgesCol = doc.createElement("td");

        int neighborhoodsize = this->getNeighborhoodsize(id);
        for(int j = 1; j <= neighborhoodsize; j++) {
            int id_d = this->getNeighbor(id, j);
            QString s_id_d = QString::number(id_d);

            QDomElement edgeElem = doc.createElement("span");

            edgeElem.setAttribute("class", "edge");
            edgeElem.setAttribute("id", "destination-"+s_id_d);

            QString textEdge = "[ ID-DEST = " + s_id_d + " { EDGE-VALUE = " + QString::number(this->getEdgeValue(id, id_d)) + " } ] ";
            QDomText textEdgeElem = doc.createTextNode(textEdge);

            edgeElem.appendChild(textEdgeElem);
            edgesCol.appendChild(edgeElem);

        }
        elemLineNode.appendChild(edgesCol);
        
        elemTable.appendChild(elemLineNode);
    }
    if(elemTable.hasChildNodes())
        elemFieldset.appendChild(elemTable);
    doc.appendChild(elemFieldset);
    return doc;
}
#endif	/* Graph_H */

