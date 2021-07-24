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
 * Case 19 : Default constructor; various inserts; various swaps; print.
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

    for (int i = 0 ; i < 4 ; ++i) {
        std::cout << "-> Swapping nodes at index " << (i + 1) << " and index " << i << "." << std::endl;

        Node<int> *node1 = llist.getNodeAtIndex(i+1);
        Node<int> *node2 = llist.getNodeAtIndex(i);

        int node1Data = node1->data;
        int node2Data = node2->data;

        llist.swapNodes(node1, node2);

        if (node1Data != node1->data || node2Data != node2->data) {
            std::cout << "you are not allowed to just swap the data in nodes" << std::endl;
            return 0;
        }

        bool node1ExistsInTheList = false;
        bool node2ExistsInTheList = false;
        Node<int> *temp = llist.getActualHead();
        while (temp && temp->next) {
            if (temp == node1) node1ExistsInTheList = true;
            else if (temp == node2) node2ExistsInTheList = true;
            temp = temp->next;
        }

        if (node1ExistsInTheList == false || node2ExistsInTheList == false) {
            std::cout << "you are not allowed to create new nodes" << std::endl;
            return 0;
        }

        std::cout << "-> Printing the list." << std::endl;

        llist.traverse();
        traverseReverse(&llist);
        printSizeIncludingDummies(&llist);
    }

    return 0;
}
