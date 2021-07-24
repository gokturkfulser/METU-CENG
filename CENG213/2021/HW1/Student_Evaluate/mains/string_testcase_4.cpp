#include <iostream>

#include "String.h"
//#include "../String.h"

/*
 * Case 4 : Default constructor; various inserts; getLength and isEmpty; print.
 */
int main() {
    std::cout << "-> Creating a string with default constructor." << std::endl;

    String str;

    std::cout << "-> Appending and inserting some characters to the string." << std::endl;

    str.appendCharacter('e');
    str.appendCharacter('h');
    str.insertCharacter('m', 0);
    str.appendCharacter('b');
    str.insertCharacter('r', 2);
    str.appendCharacter('a');
    str.insertCharacter('a', 4);

    std::cout << "-> Printing the string." << std::endl;

    str.print(true);

    std::cout << "-> Calculating the length." << std::endl;

    std::cout << "length is " << str.getLength() << std::endl;

    std::cout << "-> Checking if the string is empty or not." << std::endl;

    if (str.isEmpty()) {
        std::cout << "string is empty" << std::endl;
    } else {
        std::cout << "string is not empty" << std::endl;
    }

    return 0;
}
