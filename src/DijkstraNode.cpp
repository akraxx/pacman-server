#include "DijkstraNode.h"
#include "Graph.h"

DijkstraNode::DijkstraNode(int id, int weight) : FibonacciHeapNode(id, weight) {
    this->previous = NULL;
    this->visited = false;
    this->isInHeap = false;
}
void DijkstraNode::setVisited(bool visited) {
    this->visited = visited;
}
bool DijkstraNode::isVisited() const {
    return visited;
}
void DijkstraNode::setPrevious(DijkstraNode* previous) {
    this->previous = previous;
}
DijkstraNode* DijkstraNode::getPrevious() const {
    return previous;
}
void DijkstraNode::setIsInHeap(bool isInHeap) {
    this->isInHeap = isInHeap;
}
bool DijkstraNode::isIsInHeap() const {
    return isInHeap;
}


