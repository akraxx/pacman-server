#include "GraphResponse.h"

EmptyGraphListResponse::EmptyGraphListResponse() {
    qDebug() << "### GET GRAPH LIST, BUT GRAPHLIST IS EMPTY ###";
}

GraphSerializerResponse::GraphSerializerResponse() {

}

GraphSerializerResponse::~GraphSerializerResponse() {
    delete this->serializer;
}

GraphXmlResponse::GraphXmlResponse() {
    this->serializer = new GraphSerializerXml();
}

GraphJsonResponse::GraphJsonResponse() {
    this->serializer = new GraphSerializerJson();
}

void GraphSerializerResponse::serializeGraphList(GraphList* graphs) {
    this->serializer->serializeGraphList(graphs);
    this->content = this->serializer->getSerializedGraph();
}

void GraphSerializerResponse::serializeGraph(int id, GraphQt<DEFAULT_TYPEVAL>* graph) {
    this->serializer->serializeGraph(id, graph);
    this->content = this->serializer->getSerializedGraph();
}

GraphListXmlResponse::GraphListXmlResponse(GraphList* graphs) {
    this->serializeGraphList(graphs);
    qDebug() << "### GET XML GRAPH LIST ###";
}

GraphListJsonResponse::GraphListJsonResponse(GraphList* graphs) {
    this->serializeGraphList(graphs);
    qDebug() << "### GET JSON GRAPH LIST ###";
}

CreateGraphResponse::CreateGraphResponse() {
    
}

HasBeenCreateGraphResponse::HasBeenCreateGraphResponse(QString location) : Response(location) {
    qDebug() << "### A GRAPH HAS BEEN CREATED ###";
}

BadCreateGraphResponse::BadCreateGraphResponse() {
    qDebug() << "### CAN'T CREATE A GRAPH ###";
}

BadFormatGraphResponse::BadFormatGraphResponse() {
    qDebug() << "### THIS FORMAT IS NOT SUPPORTED ###";
}

BadGraphResponse::BadGraphResponse() {

}

BadMethodGraphResponse::BadMethodGraphResponse() {
    qDebug() << "### UNKNOWN METHOD ###";
}

NotFoundGraphResponse::NotFoundGraphResponse() {
    qDebug() << "### GRAPH HAS NOT BEEN FOUND ###";
}

HasBeedEditGraphResponse::HasBeedEditGraphResponse() {
    qDebug() << "### GRAPH HAS BEEN EDITED ###";
}

HasBeenDeleteGraphResponse::HasBeenDeleteGraphResponse() {
    qDebug() << "### GRAPH HAS BEEN DELETED ###";
}

GetGraphXmlResponse::GetGraphXmlResponse(int id, GraphQt<DEFAULT_TYPEVAL>* graph) {
    this->serializeGraph(id, graph);
    qDebug() << "### GET GRAPH IN XML ###";
}

GetGraphJsonResponse::GetGraphJsonResponse(int id, GraphQt<DEFAULT_TYPEVAL>* graph) {
    this->serializeGraph(id, graph);
    qDebug() << "### GET GRAPH IN JSON ###";
}

EmptyGraphResponse::EmptyGraphResponse() {
    qDebug() << "### GRAPH IS EMPTY ###";
}
