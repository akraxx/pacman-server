/* 
 * File:   FibonacciNode.h
 * Author: isen
 *
 * Created on 24 avril 2011, 17:29
 */

#ifndef FIBONACCINODE_H
#define	FIBONACCINODE_H

#include "utils.h"

class FibonacciHeapNode {
/* PRIVATE VARIABLES
 * @id = id of the node
 * @weight = weight od the node
 * @degree = number of childs
 * @mark = node marked or not
 *
 * @left = a pointer to the left node
 * @right = a pointer to the right node
 * @child = a pointer to the child node
 * @parent = a pointer to the parent node
 * */
private:
    int id;
    int weight;
    int degree;

    bool mark;

    FibonacciHeapNode* left;
    FibonacciHeapNode* right;
    FibonacciHeapNode* child;
    FibonacciHeapNode* parent;
public:
    /* CONSTRUCTOR */
    FibonacciHeapNode(int id, int weight);

    /**
     * Creates a String representation of this Fibonacci node heap.
     *
     * @return String of this.
     */
    QString toString();

    /* SETTERS AND GETTERS */
    void setParent(FibonacciHeapNode* parent) {
        this->parent = parent;
    }
    FibonacciHeapNode* getParent() const {
        return parent;
    }
    void setChild(FibonacciHeapNode* child) {
        this->child = child;
    }
    FibonacciHeapNode* getChild() const {
        return child;
    }
    void setRight(FibonacciHeapNode* right) {
        this->right = right;
    }
    FibonacciHeapNode* getRight() const {
        return right;
    }
    void setLeft(FibonacciHeapNode* left) {
        this->left = left;
    }
    FibonacciHeapNode* getLeft() const {
        return left;
    }

    void setMark(bool mark) {
        this->mark = mark;
    }
    bool isMark() const {
        return mark;
    }

    void increaseDegree() {
        this->degree++;
    }
    void decreaseDegree() {
        this->degree--;
    }
    int getDegree() const {
        return degree;
    }

    void setWeight(int weight) {
        this->weight = weight;
    }
    int getWeight() const {
        return weight;
    }

    void setId(int id) {
        this->id = id;
    }
    int getId() const {
        return id;
    }
};


#endif	/* FIBONACCINODE_H */

