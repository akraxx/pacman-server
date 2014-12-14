/* 
 * File:   FibonacciHeap.h
 * Author: isen
 *
 * Created on 24 avril 2011, 17:25
 */

#ifndef FIBONACCIHEAP_H
#define	FIBONACCIHEAP_H

#include "FibonacciHeapNode.h"

class FibonacciHeap {
    /* PRIVATE VARIABLES
 * @nbNodes = number of nodes in the heap
 * @minNode = a pointer to the min node
 * */
private:
    int nbNodes;
    FibonacciHeapNode* minNode;

    /**
     * Performs a cascading cut operation. This cuts y from its parent and then
     * does the same for its parent, and so on up the tree.
     *
     * Running time: O(log n); O(1) excluding the recursion
     *
     * @param y node to perform cascading cut on
     */
    void cascadingCut(FibonacciHeapNode* n);
    void consolidate();

    /**
     * The reverse of the link operation: removes x from the child list of y.
     * This method assumes that min is non-null.
     *
     * Running time: O(1)
     *
     * @param x child of y to be removed from y's child list
     * @param y parent of x about to lose a child
     */
    void cut(FibonacciHeapNode* x, FibonacciHeapNode* y);

    /**
     * Make node y a child of node x.
     *
     * Running time: O(1) actual
     *
     * @param y node to become child
     * @param x node to become parent
     */
    void link(FibonacciHeapNode* y, FibonacciHeapNode* x);
public:
    /* CONSTRUCTOR */
    FibonacciHeap();
    /* DESTRUCTOR */
    ~FibonacciHeap();

    bool isEmpty();

    /**
     * Decreases the key value for a heap node, given the new value to take on.
     * The structure of the heap may be changed and will not be consolidated.
     *
     * Running time: O(1) amortized
     *
     * @param nodes node to decrease the weight of
     * @param weight new weight value for node node
     *
     * @exception IllegalArgumentException Thrown if k is larger than x.key
     * value.
     */
    void decreaseKey(FibonacciHeapNode* node, int weight);

    /**
     * Deletes a node from the heap given the reference to the node. The trees
     * in the heap will be consolidated, if necessary. This operation may fail
     * to remove the correct element if there are nodes with key value
     * -Infinity.
     *
     * Running time: O(log n) amortized
     *
     * @param x node to remove from heap
     */
    void deleteNode(FibonacciHeapNode* x);

    /**
     * Inserts a new data element into the heap. No heap consolidation is
     * performed at this time, the new node is simply inserted into the root
     * list of this heap.
     *
     * Running time: O(1) actual
     *
     * @param node new node to insert into heap
     */
    void insertNode(FibonacciHeapNode* node);

    /**
     * Returns the smallest element in the heap. This smallest element is the
     * one with the minimum key value.
     *
     * Running time: O(1) actual
     *
     * @return heap node with the smallest key
     */
    FibonacciHeapNode* min() { return minNode; };

    /**
     * Removes the smallest element from the heap. This will cause the trees in
     * the heap to be consolidated, if necessary.
     *
     * Running time: O(log n) amortized
     *
     * @return node with the smallest key
     */
    FibonacciHeapNode* removeMin();

    /**
     * Returns the size of the heap which is measured in the number of elements
     * contained in the heap.
     *
     * Running time: O(1) actual
     *
     * @return number of elements in the heap
     */
    int size() { return nbNodes; };

    /**
     * Creates a String representation of this Fibonacci heap.
     *
     * @return String of this.
     */
    QString toString();


};


#endif	/* FIBONACCIHEAP_H */

