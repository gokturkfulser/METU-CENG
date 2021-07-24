#include <iostream>

#include "LinkedList.h"

int main() {
    std::cout << "-> Creating a linked list with default constructor." << std::endl;

    LinkedList<int> llist;

    std::cout << "-> Printing the list." << std::endl;

    llist.traverse();

    std::cout << "-> Making some insertions to the list." << std::endl;

    llist.insertAtTheEnd(6);
    llist.insertAtTheBeginning(2);
    llist.insertBeforeGivenNode(4, llist.getNode(6));

    std::cout << "-> Printing the list." << std::endl;

    llist.traverse();

    std::cout << "-> Deleting the middle node from the list." << std::endl;

    llist.deleteNode(4);

    std::cout << "-> Printing the list." << std::endl;

    llist.traverse();

    return 0;
}
