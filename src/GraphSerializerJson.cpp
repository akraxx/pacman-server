#include "GraphSerializerJson.h"

GraphSerializerJson::GraphSerializerJson() {
    this->json = this->json.toHash();
    this->parent = NULL;
}

GraphSerializerJson::~GraphSerializerJson() {

}

void GraphSerializerJson::serializeGraphList(GraphList* graphs) {

    QVariantList GraphList;
    /* SERIALIZE ALL THE GRAPHS */
    QHashIterator<int, GraphQt<DEFAULT_TYPEVAL>*> i(graphs->getGraphList());
    while (i.hasNext()) {
        QVariantHash Graph;
        /* SET THE PARENT TO THE CURRENT HASH GRAPH */
        this->parent = &Graph;
        i.next();
        this->serializeGraph(i.key(), i.value());
        /* APPEND TO THE SERIALIZED LIST */
        GraphList << Graph;
    }

    this->json = GraphList;
}

void GraphSerializerJson::serializeGraph(int id, GraphQt<DEFAULT_TYPEVAL>* graph) {
    this->addToParent("oriented", graph->isOriented());
    this->addToParent("id", id);
    /* SAVE THE GRAPH PARENT */
    QVariantHash* GraphParent = this->parent;

    QVariantList nodes;
    QVariantList edges;

    int order = graph->getOrder();
    /* SERIALIZE NODES */
    for(int i = 1; i <= order; i++) {
        QVariantHash node;
        /* SET THE PARENT TO THE CURRENT HASH NODE */
        this->parent = &node;
        int nodeId = graph->getIdByIndex(i);
        this->serializeNode(graph, nodeId);
        nodes << node;

        /* SERIALIZE EDGES */
        for(int j = 1; j <= graph->getNeighborhoodsize(nodeId); j++) {
            QVariantHash edge;
            /* SET THE PARENT TO THE CURRENT HASH EDGE */
            this->parent = &edge;
            this->serializeEdge(graph, nodeId, graph->getNeighbor(nodeId, j));
            edges << edge;
        }

    }
    /* GET BACK THE GRAPH PARENT */
    this->parent = GraphParent;
    /* APPEND NODES AND EDGES LIST */
    this->addToParent("nodes", nodes);
    this->addToParent("edges", edges);
}

void GraphSerializerJson::serializeNode(GraphQt<DEFAULT_TYPEVAL>* graph, int id) {
    this->addToParent("id", id);

    if(graph->getNodeValue(id) == UNDEFINED_VALUE)
        this->addToParent("value", "undefined");
    else
        this->addToParent("value", graph->getNodeValue(id));
}

void GraphSerializerJson::serializeEdge(GraphQt<DEFAULT_TYPEVAL>* graph, int id1, int id2) {
    this->addToParent("first-node", id1);
    this->addToParent("second-node", id2);
    
    if(graph->getEdgeValue(id1, id2) == UNDEFINED_VALUE)
        this->addToParent("value", "undefined");
    else
        this->addToParent("value", graph->getEdgeValue(id1, id2));
    
}

QString GraphSerializerJson::getSerializedGraph() {
    QJson::Serializer serializer;
    return serializer.serialize(this->json);
}

void GraphSerializerJson::addToParent(QString name, QVariant value) {
    if(this->parent)
        this->parent->insert(name, value);
    else {
        QVariantHash tmp = this->json.toHash();
        tmp.insert(name, value);
        this->json = tmp;
    }
}

