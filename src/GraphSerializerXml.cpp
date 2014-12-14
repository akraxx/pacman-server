#include "GraphSerializerXml.h"


#include "GraphQt.h"

GraphSerializerXml::GraphSerializerXml() : xml("test") {
    this->parent = NULL;
}

GraphSerializerXml::~GraphSerializerXml() {

}

void GraphSerializerXml::serializeGraphList(GraphList* GraphList) {
    QDomElement elemGraphList = xml.createElement("graph-list");
    /* SET THE PARENT TO THE GRAPH LIST ELEMENT */
    this->parent = &elemGraphList;

    /* SERIALIZE ALL THE GRAPHS */
    QHashIterator<int, GraphQt<DEFAULT_TYPEVAL>*> i(GraphList->getGraphList());
    while (i.hasNext()) {
        i.next();
        this->serializeGraph(i.key(), i.value());
    }

    /* SET THE DTD TO GRAPH LIST AND APPEND GRAPHLISTELEMENT TO THE DOCUMENT */
    this->dtd = "graph-list";
    this->parent = NULL;
    this->appendToParent(&elemGraphList);
}

void GraphSerializerXml::serializeGraph(int id, GraphQt<DEFAULT_TYPEVAL>* graph) {
    /* SET THE DTD TO GRAPH */
    this->dtd = "graph";
    QDomElement elemGraph = xml.createElement("graph");
    if(graph->isOriented())
        elemGraph.setAttribute("oriented", "true");
    else
        elemGraph.setAttribute("oriented", "false");
    
    elemGraph.setAttribute("id", id);
    elemGraph.setAttribute("name", graph->getName());

    /* SAVE THE PARENT GRAPH */
    QDomElement* parentGraph = this->parent;
    QDomElement elemNodes = xml.createElement("nodes");
    QDomElement elemEdges = xml.createElement("edges");

    int order = graph->getOrder();
    /* SERIALIZE NODES */
    for(int i = 1; i <= order; i++) {
        /* SET THE PARENT TO THE CURRENT ELEM NODES */
        this->parent = &elemNodes;
        int nodeId = graph->getIdByIndex(i);
        this->serializeNode(graph, nodeId);
        /* SET THE PARENT TO THE CURRENT ELEM EDGES */
        this->parent = &elemEdges;
        /* SERIALIZE EDGES */
        for(int j = 1; j <= graph->getNeighborhoodsize(nodeId); j++)
            this->serializeEdge(graph, nodeId, graph->getNeighbor(nodeId, j));

    }

    /* APPEND NODES AND EDGES TO THE GRAPH */
    this->parent = &elemGraph;
    this->appendToParent(&elemNodes);
    this->appendToParent(&elemEdges);

    /* GET BACK THE PARENT GRAPH AND ADD THE GRAPH TO IT */
    this->parent = parentGraph;
    this->appendToParent(&elemGraph);
}

void GraphSerializerXml::serializeNode(GraphQt<DEFAULT_TYPEVAL>* graph, int id) {
    QDomElement elemNode = xml.createElement("node");
    elemNode.setAttribute("id", id);

    if(graph->getNodeValue(id) == UNDEFINED_VALUE)
        elemNode.setAttribute("value", "undefined");
    else
        elemNode.setAttribute("value", graph->getNodeValue(id));

    this->appendToParent(&elemNode);
}

void GraphSerializerXml::serializeEdge(GraphQt<DEFAULT_TYPEVAL>* graph, int id1, int id2) {
    QDomElement elemEdge = xml.createElement("edge");
    elemEdge.setAttribute("first-node", id1);
    elemEdge.setAttribute("second-node", id2);
    if(graph->getEdgeValue(id1, id2) == UNDEFINED_VALUE)
        elemEdge.setAttribute("value", "undefined");
    else
        elemEdge.setAttribute("value", graph->getEdgeValue(id1, id2));

    this->appendToParent(&elemEdge);
}

QString GraphSerializerXml::getSerializedGraph() {
    /* SET THE DTD AND THE XML VERSION */
    QDomDocument out(this->dtd);
    out.appendChild(out.createProcessingInstruction("xml", "version=\"1.0\" standalone=\"yes\""));
    out.appendChild(this->xml);
    return out.toString();
}

void GraphSerializerXml::appendToParent(QDomElement* elem) {
    if(parent)
        parent->appendChild(*elem);
    else
        xml.appendChild(*elem);
}
