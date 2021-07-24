#include <iostream>

#include "String.h"
//#include "../String.h"

/*
 * Case 8 : String constructor; substring; print.
 */
int main() {
    std::cout << "-> Creating a string with string constructor." << std::endl;

    char chr[] = "merhaba dunya";
    String str(chr);

    std::cout << "-> Printing the string." << std::endl;

    str.print(true);

    std::cout << "-> Getting all substrings." << std::endl;

    for (int pos = 0; pos < str.getLength(); ++pos) {
        for (int len = 0; (pos + len) <= str.getLength(); ++len) {
            std::cout << "substring from pos=" << pos << " and len=" << len << " is: ";
            str.substring(pos, len).print(false);
        }
    }

    std::cout << "-> Printing the string." << std::endl;

    str.print(true);

    return 0;
}
