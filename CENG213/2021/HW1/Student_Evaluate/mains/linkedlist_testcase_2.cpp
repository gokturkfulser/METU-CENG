#include <iostream>

#include "LinkedList.h"
//#include "../LinkedList.h"

template<class T>
void printSizeIncludingDummies(LinkedList<T> *llist) {
    std::cout << "-> Calculating the size including dummies." << std::endl;

    int count = 0;

    Node<T> *temp = llist->getDummyHead();

    while (temp) {
        count += 1;
        temp = temp->next;
    }

    std::cout << "size is " << count << std::endl;
}

template<class T>
void traverseReverse(LinkedList<T> *llist) {
    std::cout << "-> Printing the list in reverse." << std::endl;

    if (llist == NULL) {
        std::cout << "NULL" << std::endl;
        return;
    } else if (llist->isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    } else {
        Node<T> *node = llist->getActualTail();

        while (node && node->prev) {
            std::cout << *node << std::endl;
            node = node->prev;
        }
    }
}

/*
 * Case 2 : Default constructor; various utility functions on empty linked list; print.
 */
int main() {
    std::cout << "-> Creating a linked list with default constructor." << std::endl;

    LinkedList<int> llist;

    std::cout << "-> Getting the first data node." << std::endl;

    if (llist.getActualHead() == NULL) {
        std::cout << "no first data node" << std::endl;
    }

    std::cout << "-> Getting the last data node." << std::endl;

    if (llist.getActualTail() == NULL) {
        std::cout << "no last data node" << std::endl;
    }

    std::cout << "-> Getting the dummy head node." << std::endl;

    if (llist.getDummyHead() != NULL) {
        std::cout << "there exists a dummy head node" << std::endl;
    }

    std::cout << "-> Getting the dummy tail node." << std::endl;

    if (llist.getDummyTail() != NULL) {
        std::cout << "there exists a dummy tail node" << std::endl;
    }

    std::cout << "-> Calculating the size." << std::endl;

    if (llist.getSize() == 0) {
        std::cout << "size is zero" << std::endl;
    }

    std::cout << "-> Checking if the list is empty or not." << std::endl;

    if (llist.isEmpty()) {
        std::cout << "linked list is empty" << std::endl;
    }

    std::cout << "-> Printing the list." << std::endl;

    llist.traverse();
    traverseReverse(&llist);
    printSizeIncludingDummies(&llist);

    return 0;
}
