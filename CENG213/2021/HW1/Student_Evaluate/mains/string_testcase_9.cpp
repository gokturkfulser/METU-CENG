#include <iostream>

#include "String.h"
//#include "../String.h"

/*
 * Case 9 : String constructor; split; print.
 */
int main() {
    std::cout << "-> Creating a string with string constructor." << std::endl;

    char chr[] = "merhaba dunya";
    String str(chr);

    std::cout << "-> Printing the string." << std::endl;

    str.print(true);

    std::cout << "-> Splitting the string with space character as the separator and printing the list." << std::endl;

    LinkedList<String> words = str.split(' ');

    words.traverse();

    std::cout << "-> Splitting the string with a character as the separator and printing the list." << std::endl;

    LinkedList<String> lSplits = str.split('a');

    lSplits.traverse();

    std::cout << "-> Printing the string." << std::endl;

    str.print(true);

    return 0;
}
