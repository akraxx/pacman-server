#include "DijkstraSerializerJson.h"

DijkstraSerializerJson::DijkstraSerializerJson(QVariantList pathAndCost) : DijkstraSerializer(pathAndCost) {

}

DijkstraSerializerJson::~DijkstraSerializerJson() {

}

QString DijkstraSerializerJson::getSerializedDijkstra() {
    QVariantHash r;
    r.insert("total-cost", this->cost);
    r.insert("nodes", this->path);

    QJson::Serializer serializer;
    return serializer.serialize(r);
}
