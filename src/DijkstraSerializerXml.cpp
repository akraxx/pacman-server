#include "DijkstraSerializerXml.h"

DijkstraSerializerXml::DijkstraSerializerXml(QVariantList pathAndCost) : DijkstraSerializer(pathAndCost) {

}

DijkstraSerializerXml::~DijkstraSerializerXml() {

}

QString DijkstraSerializerXml::getSerializedDijkstra() {
    QDomDocument d("path");

    QDomElement pathElem = d.createElement("path");
    pathElem.setAttribute("total-cost", this->cost);

    int nbElems = this->path.size();
    for(int i = 0; i < nbElems; i++) {
        QDomElement nodeElem = d.createElement("node");
        nodeElem.setAttribute("id", this->path.at(i).toInt());
        pathElem.appendChild(nodeElem);
    }

    d.appendChild(pathElem);

    return d.toString();
}