#include "DijkstraParser.h"

DijkstraParser::DijkstraParser(QByteArray pathinfo, QHash<QByteArray,QByteArray> query) : Parser(pathinfo, query) {

}

/* NOT IMPLEMENTED YET */
void DijkstraParser::parseQuery() {
    data["start"] = this->query["start"];
    data["goal"] = this->query["goal"];
}
