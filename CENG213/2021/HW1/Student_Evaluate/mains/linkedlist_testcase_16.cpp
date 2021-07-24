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
 * Case 16 : Default constructor; various inserts; assignment operator; print.
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

    std::cout << "-> Creating a duplicate linked list with assignment constructor." << std::endl;

    LinkedList<int> duplicatedLList;
    duplicatedLList = llist;

    std::cout << "-> Printing the duplicate list." << std::endl;

    duplicatedLList.traverse();
    traverseReverse(&duplicatedLList);
    printSizeIncludingDummies(&duplicatedLList);

    std::cout << "-> Printing the list." << std::endl;

    llist.traverse();
    traverseReverse(&llist);
    printSizeIncludingDummies(&llist);

    std::cout << "-> Removing a node from the original list." << std::endl;

    llist.deleteNode(llist.getNode(33));

    std::cout << "-> Printing the duplicate list." << std::endl;

    duplicatedLList.traverse();
    traverseReverse(&duplicatedLList);
    printSizeIncludingDummies(&duplicatedLList);

    std::cout << "-> Printing the list." << std::endl;

    llist.traverse();
    traverseReverse(&llist);
    printSizeIncludingDummies(&llist);

    return 0;
}
