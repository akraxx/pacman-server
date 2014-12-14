#include "DijkstraSerializer.h"

DijkstraSerializer::DijkstraSerializer(QVariantList pathAndCost) {
    this->cost = pathAndCost.first().toInt();
    pathAndCost.removeFirst();
    this->path = pathAndCost;
}

DijkstraSerializer::~DijkstraSerializer() {

}
