#include <iostream>

#include "String.h"
//#include "../String.h"

/*
 * Case 3 : Default constructor; various functions on empty string; print.
 */
int main() {
    std::cout << "-> Creating a string with default constructor." << std::endl;

    String str;

    std::cout << "-> Trying to erase first two characters from the string and then printing the string." << std::endl;

    str.eraseCharacters(0, 2);
    str.print(true);

    std::cout << "-> Trying to erase all characters from the string and then printing the string." << std::endl;

    str.eraseAllCharacters();
    str.print(true);

    std::cout << "-> Printing the string." << std::endl;

    str.print(true);

    return 0;
}
