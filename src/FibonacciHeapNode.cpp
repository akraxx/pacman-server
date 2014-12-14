#include "FibonacciHeapNode.h"

FibonacciHeapNode::FibonacciHeapNode(int id, int weight) {
    this->setId(id);
    this->setWeight(weight);
    this->setRight(this);
    this->setLeft(this);
    this->setParent(NULL);
    this->setChild(NULL);
    this->degree = 0;
}

QString FibonacciHeapNode::toString() {
    QString r;
    r.append("Node=[parent = ");

    if (this->parent != NULL)
        r.append(QString::number(this->parent->getId()));
    else
        r.append("---");

    r.append(", id = ");
    r.append(QString::number(this->id));
    r.append(", degree = ");
    r.append(QString::number(this->degree));
    r.append(", weight = ");
    r.append(QString::number(this->weight));
    r.append(", right = ");

    if (this->right != NULL)
        r.append(QString::number(this->right->getId()));
    else
        r.append("---");

    r.append(", left = ");

    if (this->left != NULL)
        r.append(QString::number(this->left->getId()));
    else
        r.append("---");

    r.append(", child = ");

    if (this->child != NULL)
        r.append(QString::number(this->child->getId()));
    else
        r.append("---");

    r.append(']');

    return r;
}