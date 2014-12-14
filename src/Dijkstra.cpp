#include "Dijkstra.h"
#include "Graph.h"
#include "DijkstraNode.h"
#include "DijkstraException.h"

Dijkstra::Dijkstra(Graph<int>* g) {
    this->graph = g;
}

Dijkstra::~Dijkstra() {

}

QVariantList Dijkstra::findShortestPath(int start, int goal) {
    if(!this->graph->nodeExists(start))
        throw NodeNotFoundException("Can't search a path", start);
    if(!this->graph->nodeExists(goal))
        throw NodeNotFoundException("Can't search a path", goal);

    qDebug() << "BEFORE : " << QTime::currentTime().toString("hh:mm:ss.zzz");

    FibonacciHeap heap;
    QHash<int, DijkstraNode*> nodes;
    int order = this->graph->getOrder();
    int nodeId;
    nodes.reserve(order);
    for(int i = 1; i <= order; i++) {
        nodeId = this->graph->getIdByIndex(i);
        DijkstraNode* node = new DijkstraNode(nodeId, -1);
        nodes.insert(nodeId, node);
    }
    
    heap.insertNode(nodes[start]);
    nodes[start]->setIsInHeap(true);
    nodes[start]->setWeight(0);
    bool finish = false;

   
    while(!heap.isEmpty() && !finish) {

        FibonacciHeapNode* node = heap.removeMin();
        
        nodeId = node->getId();

        nodes[nodeId]->setVisited(true);
        
        QList<int> neighbors = this->graph->getNeighbors(nodeId);
        
        int neighborhoodSize = neighbors.size();
        if(nodeId == goal)
            finish = true;


        for(int i = 0; i < neighborhoodSize && !finish; i++) {
            
            int neighborId = neighbors[i];
            DijkstraNode* node = nodes[neighborId];
            
            if(!node->isVisited() && (node->getWeight() < 0 || (nodes[nodeId]->getWeight() + this->graph->getEdgeValue(nodeId, neighborId)) < node->getWeight())) {
                node->setPrevious(nodes[nodeId]);
                 
                int newWeight = nodes[nodeId]->getWeight() + this->graph->getEdgeValue(nodeId, neighborId);
                
                if(!node->isIsInHeap()) {
                    node->setWeight(newWeight);
                   
                    heap.insertNode(node);
                    
                    node->setIsInHeap(true);
                }
                else
                    heap.decreaseKey(node, newWeight);

                
                
            }

        }
        
    }
    
    
    /* IF NO PATH HAVE BEEN FOUND */
    if(nodeId != goal)
        throw PathNotFoundException("Can't find a path", start, goal);

    /* CONSTRUCT THE PATH */
    QVariantList path;
    while(nodeId != start) {
        path.prepend(nodeId);
        nodeId = nodes[nodeId]->getPrevious()->getId();
    }
    path.prepend(start);

    /* ADD TOTAL COST TO THE BEGINNING */
    path.prepend(nodes[goal]->getWeight());

    QHashIterator<int, DijkstraNode*> i(nodes);
    while (i.hasNext()) {
        i.next();
        delete i.value();
    }

    qDebug() << "AFTER : " << QTime::currentTime().toString("hh:mm:ss.zzz");
    return path;
}