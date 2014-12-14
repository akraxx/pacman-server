/* 
 * File:   Dijkstra.h
 * Author: isen
 *
 * Created on 25 avril 2011, 18:08
 */

#ifndef DIJKSTRA_H
#define	DIJKSTRA_H

#include "utils.h"
#include "FibonacciHeap.h"
#include "Graph.h"

class Dijkstra {
    /* PRIVATE VARIABLES
 * @graph = a pointer of Graph
 * */
private:
    Graph<DEFAULT_TYPEVAL>* graph;
public:
    /* CONSTRUCTOR AND DESTRUCTORS */
    Dijkstra(Graph<DEFAULT_TYPEVAL>* g);
    ~Dijkstra();

    /* Function findShortestPath
     * ----------------------------------------
     * it search the shortest path between 2 nodes
     * ----------------------------------------
     * @start = id of the start node
     * @end = id of the end node
     * ----------------------------------------
     * @return a list, first element is the total cost
     * ----------------------------------------
     * can throw an exception if
     * -Node start or goal is missing in graph
     * -There is no path in the graph
     */
    QVariantList findShortestPath(int start, int goal);
};


#endif	/* DIJKSTRA_H */

