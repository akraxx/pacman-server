#include "FibonacciHeap.h"

/*
 * PRIVATE FUNCTIONS
 */

void FibonacciHeap::cascadingCut(FibonacciHeapNode* n) {
    FibonacciHeapNode* p = n->getParent();

    /* IF THERE IS A PARENT */
    if(p != NULL) {
        /* IF THE PARENT IS UNMARKED, SET IT MARKED */
        if (!p->isMark()) {
            p->setMark(true);
        } else {
            /* IF IT'S MARKED, CUR IT FROM PARENT */
            this->cut(n, p);

            /* CUT HIS PARENTS ASWELL */
            cascadingCut(p);
        }
    }
}

void FibonacciHeap::consolidate() {
    QHash<int, FibonacciHeapNode*> array;
    //array.reserve(this->nbNodes);
    /* FIND THE NUMBER OF ROOTS NODES */
    int numRoots = 0;
    FibonacciHeapNode* x = this->minNode;
    
    if (x != NULL) {
        numRoots++;
        x = x->getRight();

        while (x != this->minNode) {
            numRoots++;
            x = x->getRight();
        }
    }

    /* FOR EACH NODE IN ROOT LIST DO */
    while (numRoots > 0) {
        /* ACCESS THIS NODE'S WEIGHT */
        int d = x->getDegree();
        FibonacciHeapNode* next = x->getRight();

        bool found = true;
        /* SEE IF THERE'S ANOTHER OF THE SAME DEGREE */
        while(found) {
            FibonacciHeapNode* y = array[d];
            if (y == NULL)
                found = false;
            else {
                // There is, make one of the nodes a child of the other.
                // Do this based on the key value.
                if (x->getWeight() > y->getWeight()) {
                    FibonacciHeapNode* temp = y;
                    y = x;
                    x = temp;
                }

                // FibonacciHeapNode<T> y disappears from root list.
                link(y, x);

                // We've handled this degree, go to next one.
                array[d] = NULL;
                d++;
            }
        }

        // Save this node for later when we might encounter another
        // of the same degree.
        array[d] = x;

        // Move forward through list.
        x = next;
        numRoots--;
    }

    // Set min to null (effectively losing the root list) and
    // reconstruct the root list from the array entries in array[].
    this->minNode = NULL;
    QHashIterator<int, FibonacciHeapNode*> i(array);
    while(i.hasNext()) {
        i.next();
        FibonacciHeapNode* y = i.value();
        if (y != NULL) {
            // We've got a live one, add it to root list.
            if (this->minNode != NULL) {
                // First remove node from root list.
                y->getLeft()->setRight(y->getRight());
                y->getRight()->setLeft(y->getLeft());

                // Now add to root list, again.
                y->setLeft(this->minNode);
                y->setRight(this->minNode->getRight());
                this->minNode->setRight(y);
                y->getRight()->setLeft(y);

                // Check if this is a new min.
                if (y->getWeight() < this->minNode->getWeight()) {
                    this->minNode = y;
                }
            }
            else
                this->minNode = y;
        }
    }
}

void FibonacciHeap::cut(FibonacciHeapNode* x, FibonacciHeapNode* y) {
    // remove x from childlist of y and decrement degree[y]
    x->getLeft()->setRight(x->getRight());
    x->getRight()->setLeft(x->getLeft());
    y->decreaseDegree();

    // reset y.child if necessary
    if (y->getChild() == x) {
        y->setChild(x->getRight());
    }

    if (y->getDegree() == 0) {
        y->setChild(NULL);
    }

    // add x to root list of heap
    x->setLeft(this->minNode);
    x->setRight(this->minNode->getRight());
    this->minNode->setRight(x);
    x->getRight()->setLeft(x);

    // set parent[x] to nil
    x->setParent(NULL);

    // set mark[x] to false
    x->setMark(false);
}

void FibonacciHeap::link(FibonacciHeapNode* y, FibonacciHeapNode* x) {
    // remove y from root list of heap
    y->getLeft()->setRight(y->getRight());
    y->getRight()->setLeft(y->getLeft());

    // make y a child of x
    y->setParent(x);

    if (x->getChild() == NULL) {
        x->setChild(y);
        y->setRight(y);
        y->setLeft(y);
    } else {
        y->setLeft(x->getChild());
        y->setRight(x->getChild()->getRight());
        x->getChild()->setRight(y);
        y->getRight()->setLeft(y);
    }

    // increase degree[x]
    x->increaseDegree();

    // set mark[y] false
    y->setMark(false);
}

FibonacciHeap::FibonacciHeap() {
    this->minNode = NULL;
    this->nbNodes = 0;
}

FibonacciHeap::~FibonacciHeap() {

}

bool FibonacciHeap::isEmpty() {
    return (this->nbNodes ? false : true);
}

void FibonacciHeap::decreaseKey(FibonacciHeapNode* x, int weight) {
    
    if (weight < x->getWeight()) {
        x->setWeight(weight);

        FibonacciHeapNode* y = x->getParent();

        if ((y != NULL) && (x->getWeight() < y->getWeight())) {
            cut(x, y);
            cascadingCut(y);
        }

        if (x->getWeight() < this->minNode->getWeight())
            this->minNode = x;
    }
}

void FibonacciHeap::deleteNode(FibonacciHeapNode* x) {
    // make x as small as possible
    decreaseKey(x, -1);

    // remove the smallest, which decreases n also
    removeMin();
}

void FibonacciHeap::insertNode(FibonacciHeapNode* node) {
    // concatenate node into min list
    if (this->minNode != NULL) {
        node->setLeft(this->minNode);
        node->setRight(this->minNode->getRight());
        this->minNode->setRight(node);
        node->getRight()->setLeft(node);

        if (node->getWeight() < this->minNode->getWeight()) {
            this->minNode = node;
        }
    }
    else
        this->minNode = node;

    this->nbNodes++;
}

FibonacciHeapNode* FibonacciHeap::removeMin() {
    FibonacciHeapNode* z = this->minNode;

    if (z != NULL) {
        int numKids = z->getDegree();
        FibonacciHeapNode* x = z->getChild();
        FibonacciHeapNode* tempRight;
        // for each child of z do...
        while (numKids > 0) {
            tempRight = x->getRight();

            // remove x from child list
            x->getLeft()->setRight(x->getRight());
            x->getRight()->setLeft(x->getLeft());

            // add x to root list of heap
            x->setLeft(this->minNode);
            x->setRight(this->minNode->getRight());
            this->minNode->setRight(x);
            x->getRight()->setLeft(x);

            // set parent[x] to null
            x->setParent(NULL);
            x = tempRight;
            numKids--;
        }
        // remove z from root list of heap
        z->getLeft()->setRight(z->getRight());
        z->getRight()->setLeft(z->getLeft());

        if (z == z->getRight()) {
            this->minNode = NULL;
        } else {
            this->minNode = z->getRight();
            consolidate();
        }

        // decrement size of heap
        this->nbNodes--;
    }
    
    return z;
}

QString FibonacciHeap::toString() {
    if (this->minNode == NULL) {
        return "FibonacciHeap=[]";
    }

    // create a new stack and put root on it
    QStack<FibonacciHeapNode*> stack;
    stack.push(this->minNode);

    QString r;
    r.append("FibonacciHeap=[");

    // do a simple breadth-first traversal on the tree
    while (!stack.empty()) {
        FibonacciHeapNode* curr = stack.pop();
        r.append(curr->toString());
        r.append(", ");

        if (curr->getChild() != NULL)
            stack.push(curr->getChild());

        FibonacciHeapNode* start = curr;
        curr = curr->getRight();

        while (curr != start) {
            r.append(curr->toString());
            r.append(", ");

            if (curr->getChild() != NULL) {
                stack.push(curr->getChild());
            }

            curr = curr->getRight();
        }
    }

    r.append(']');

    return r;
}

