/* 
 * File:   DijkstraNode.h
 * Author: isen
 *
 * Created on 25 avril 2011, 18:08
 */

#ifndef DIJKSTRANODE_H
#define	DIJKSTRANODE_H

#include "FibonacciHeapNode.h"

class DijkstraNode : public FibonacciHeapNode {
/* PRIVATE VARIABLES
 * @previous = pointer on previous node
 * @visited = node has been visited or not
 * @isInHeap = node is ine heap or not
 * */
private:
    DijkstraNode* previous;
    bool visited;
    bool isInHeap;
public:
    /* CONSTRUCTOR */
    DijkstraNode(int id, int weight);

    /* SETTERS AND GETTERS */
    void setVisited(bool visited);
    bool isVisited() const;
    void setPrevious(DijkstraNode* previous);
    DijkstraNode* getPrevious() const;
    void setIsInHeap(bool isInHeap);
    bool isIsInHeap() const;
};


#endif	/* DIJKSTRANODE_H */

