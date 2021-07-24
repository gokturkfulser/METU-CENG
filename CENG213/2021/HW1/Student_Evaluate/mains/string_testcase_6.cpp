#include <iostream>

#include "String.h"
//#include "../String.h"

/*
 * Case 6 : Default constructor; various inserts; various erasures; various inserts again; print.
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

    std::cout << "-> Erasing some characters and finally erasing all characters of the string. Printing the string after each erasing." << std::endl;

    std::cout << "-> eraseCharacters ..." << std::endl;

    str.eraseCharacters(0, 1);
    str.print(true);

    std::cout << "-> eraseCharacters ..." << std::endl;

    str.eraseCharacters(3, 1);
    str.print(true);

    std::cout << "-> eraseCharacters ..." << std::endl;

    str.eraseCharacters(1, 2);
    str.print(true);

    std::cout << "-> eraseAllCharacters ..." << std::endl;

    str.eraseAllCharacters();
    str.print(true);

    std::cout << "-> Making some more insertions to the string." << std::endl;

    str.insertCharacter('d', 0);
    str.appendCharacter('u');
    str.appendCharacter('a');
    str.insertCharacter('n', 2);
    str.insertCharacter('y', 3);

    std::cout << "-> Printing the string." << std::endl;

    str.print(true);

    return 0;
}
