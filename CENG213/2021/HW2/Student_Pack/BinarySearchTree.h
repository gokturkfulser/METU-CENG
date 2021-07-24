#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


#include <iostream>
#include <stack>
#include <queue>

#include "Node.h"

template<class T>
class BinarySearchTree {
public: // DO NOT CHANGE THIS PART.
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<T> &obj);

    ~BinarySearchTree();

    Node<T> *getRoot() const;

    void insert(const T &element);
    void remove(const T &element);
    Node<T> *find(const T &element);
    Node<T> *findWithoutOrderingProperty(const T &element);

    std::vector<Node<T> *> getListOfAllNodes();

    void depthFirstTraversal() const;
    void breadthFirstTraversal() const;

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const BinarySearchTree<U> &tree);
    template <class U>
    friend std::ostream &streamOutputOperatorHelper(std::ostream &os, Node<T> *node);

    BinarySearchTree<T> &operator=(const BinarySearchTree<T> &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

private: // DO NOT CHANGE THIS PART.
    Node<T> *root;
};

template<class T>
BinarySearchTree<T>::BinarySearchTree() {
    /* TODO */
}

template<class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> &obj) {
    /* TODO */
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
    /* TODO */
}

template<class T>
Node<T> *BinarySearchTree<T>::getRoot() const {
    /* TODO */
}

template<class T>
void BinarySearchTree<T>::insert(const T &element) {
    /* TODO */
}

template<class T>
void BinarySearchTree<T>::remove(const T &element) {
    /* TODO */
}

template<class T>
Node<T> *BinarySearchTree<T>::find(const T &element) {
    /* TODO */
}

template<class T>
Node<T> *BinarySearchTree<T>::findWithoutOrderingProperty(const T &element) {
    /* TODO */
}

template<class T>
std::vector<Node<T> *> BinarySearchTree<T>::getListOfAllNodes() {
    /* TODO */
}

template<class T>
void BinarySearchTree<T>::depthFirstTraversal() const {
    /* TODO */
}

template<class T>
void BinarySearchTree<T>::breadthFirstTraversal() const {
    /* TODO */
}

template<class T>
std::ostream &operator<<(std::ostream &os, const BinarySearchTree<T> &tree) {

    // check if the tree is empty?
    if (tree.root == NULL) {
        os << "BinarySearchTree()";
        return os;
    }

    // recursively output the tree.
    os << "BinarySearchTree(" << "\n";
    streamOutputOperatorHelper(os, tree.root);
    os << "\n" << ")";

    return os;
}

template<class T>
std::ostream &streamOutputOperatorHelper(std::ostream &os, Node<T> *node) {

    // check if the node is NULL?
    if (node == NULL)
        return os;

    // outputing inorder.

    // first, output left subtree and comma (if needed).
    streamOutputOperatorHelper(os, node->left);
    if (node->left) {
        os << ", " << "\n";
    }

    // then, output the node.
    os << *node;

    // finally, output comma (if needed) and the right subtree.
    if (node->right) {
        os << ", " << "\n";
    }
    streamOutputOperatorHelper(os, node->right);

    return os;
}

template<class T>
BinarySearchTree<T> &BinarySearchTree<T>::operator=(const BinarySearchTree<T> &rhs) {
    /* TODO */
}


#endif //BINARYSEARCHTREE_H
