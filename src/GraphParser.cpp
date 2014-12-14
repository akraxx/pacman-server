#include "GraphParser.h"

/* PUBLIC */
GraphParser::GraphParser(QByteArray pathinfo, QHash<QByteArray, QByteArray> query) : Parser(pathinfo, query) {

}

void GraphParser::parseQuery() {
    data["oriented"] = this->query["oriented"];
    data["name"] = this->query["name"];

    QRegExp regNode("^node([0-9]+)$");
    QRegExp regEdge("^edge([0-9]+)-([0-9]+)$");
    QVariantList nodes;
    QVariantList edges;

    /* PARSE NODES AND EDGES */
    QHashIterator<QByteArray, QByteArray> i(this->query);
    while (i.hasNext()) {
        i.next();
        /* IF ITS A NODE*/
         if(regNode.indexIn(i.key()) > -1) {
            QVariantHash node;
            node.insert("id", regNode.cap(1).toInt());
            node.insert("value", i.value().toInt());
            /* APPEND TO THE NODES LIST */
            nodes << node;
         }
         /* IF ITS AN EDGE*/
        if(regEdge.indexIn(i.key()) > -1) {
            QVariantHash edge;
            edge.insert("first-node", regEdge.cap(1).toInt());
            edge.insert("second-node", regEdge.cap(2).toInt());
            edge.insert("value", i.value());
            /* APPEND TO THE EDGES LIST */
            edges << edge;
         }
    }
    /* INSERT NODES AND EDGES INTO DATA */
    data["edges"] = edges;
    data["nodes"] = nodes;
}

GraphQt<DEFAULT_TYPEVAL>* GraphParser::createGraph() {
    /* IF THE GRAPH HAS AN ORIENTED ARGUMENT */
    if(!data["oriented"].toString().isEmpty()) {
        /* CREATE A NEW GRAPHQT */
        GraphQt<DEFAULT_TYPEVAL>* graph = new GraphQt<DEFAULT_TYPEVAL>(data["oriented"].toBool(), true, data["name"].toString());
        /* ADD NODES */
        for(int i = 0; i < data["nodes"].toList().size(); i++) {
            QVariantHash node = data["nodes"].toList().at(i).toHash();
            graph->addNode(node["id"].toInt());
            if(node["value"] == "u") node["value"] = UNDEFINED_VALUE; /* IF THE NODE HAS UNDEFINED VALUE */
            graph->setNodeValue(node["id"].toInt(), node["value"].toInt());
        }
        /* ADD EDGES */
        for(int i = 0; i < data["edges"].toList().size(); i++) {
            QVariantHash edge = data["edges"].toList().at(i).toHash();

            graph->addEdge(edge["first-node"].toInt(), edge["second-node"].toInt());
            if(edge["value"].toString() == "u") edge["value"] = 1; /* IF THE EDGE HAS UNDEFINED VALUE SET IT TO 1 */
            graph->setEdgeValue(edge["first-node"].toInt(), edge["second-node"].toInt(), edge["value"].toInt());

        }
        return graph;
    }
    else {
        throw MissingArgumentGraphParserException("Can't create a graph", "oriented");
    }

}
