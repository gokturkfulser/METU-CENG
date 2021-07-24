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
 * Case 3 : Default constructor; various functions on empty linked list; print.
 */
int main() {
    std::cout << "-> Creating a linked list with default constructor." << std::endl;

    LinkedList<int> llist;

    std::cout << "-> Creating a node with data 33. Node is not in the list." << std::endl;

    Node<int> *tempNode = new Node<int>(33, NULL, NULL);

    std::cout << "-> Trying to delete that node from the list and then printing the list." << std::endl;

    llist.deleteNode(tempNode);
    llist.traverse();
    traverseReverse(&llist);
    printSizeIncludingDummies(&llist);

    std::cout << "-> Trying to delete a node with data 33 from the list and then printing the list." << std::endl;

    llist.deleteNode(33);
    llist.traverse();
    traverseReverse(&llist);
    printSizeIncludingDummies(&llist);

    std::cout << "-> Trying to delete all nodes from the list and then printing the list." << std::endl;

    llist.deleteAllNodes();
    llist.traverse();
    traverseReverse(&llist);
    printSizeIncludingDummies(&llist);

    std::cout << "-> Trying to get a node with data 33 from the list." << std::endl;

    if (llist.getNode(33) == NULL) {
        std::cout << "no node with data 33 exists" << std::endl;
    }

    std::cout << "-> Checking if the list contains the previously created node or not." << std::endl;
    if (llist.contains(tempNode) == false) {
        std::cout << "linked list does not contain that node" << std::endl;
    }

    std::cout << "-> Printing the list." << std::endl;

    llist.traverse();
    traverseReverse(&llist);
    printSizeIncludingDummies(&llist);

    delete tempNode;

    return 0;
}
