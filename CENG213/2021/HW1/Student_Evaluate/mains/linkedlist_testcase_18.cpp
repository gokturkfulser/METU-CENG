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
 * Case 18 : Default constructor; various inserts; various gets (getNodeAtIndex(int index)); print.
 */
int main() {
    std::cout << "-> Creating a linked list with default constructor." << std::endl;

    LinkedList<int> llist;

    std::cout << "-> Making some insertions to the list." << std::endl;

    llist.insertAtTheBeginning(32);
    llist.insertAtTheEnd(34);
    llist.insertAtTheBeginning(31);
    llist.insertAtTheEnd(35);
    llist.insertBeforeGivenNode(33, llist.getNode(34));

    std::cout << "-> Printing the list." << std::endl;

    llist.traverse();
    traverseReverse(&llist);
    printSizeIncludingDummies(&llist);

    for (int i = -1 ; i <= 5 ; ++i) {
        std::cout << "-> Getting node at index " << i << "." << std::endl;
        Node<int> *temp = llist.getNodeAtIndex(i);
        if (temp == NULL) {
            std::cout << "no node at index " << i << " exists" << std::endl;
        } else {
            std::cout << "exists. data must be " << (30 + i + 1) << ". it is " << temp->data << std::endl;
        }
    }

    std::cout << "-> Printing the list." << std::endl;

    llist.traverse();
    traverseReverse(&llist);
    printSizeIncludingDummies(&llist);

    return 0;
}
