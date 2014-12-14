#include "DijkstraResponse.h"

NotImplementedDijkstraResponse::NotImplementedDijkstraResponse() {
    qDebug() << "### DIJKSTRA IS NOT IMPLEMENTED YET ###";
}

DijkstraXmlResponse::DijkstraXmlResponse(QVariantList pathAndCost) {
    DijkstraSerializerXml s(pathAndCost);
    this->content = s.getSerializedDijkstra();

    qDebug() << "### GET PATH IN XML ###";
}

DijkstraJsonResponse::DijkstraJsonResponse(QVariantList pathAndCost) {
    DijkstraSerializerJson s(pathAndCost);
    this->content = s.getSerializedDijkstra();

    qDebug() << "### GET PATH IN JSON ###";
}

DijkstraNoPathResponse::DijkstraNoPathResponse() {
    qDebug() << "### CAN'T FIND A PATH ###";
}

DijkstraBadResponse::DijkstraBadResponse() {
    qDebug() << "### BAD OR MISSING ARGUMENT FOR DIJKSTRA ###";
}