#include <iostream>

#include "String.h"
//#include "../String.h"

/*
 * Case 2 : Default constructor; various utility functions on empty string; print.
 */
int main() {
    std::cout << "-> Creating a string with default constructor." << std::endl;

    String str;

    std::cout << "-> Calculating the length." << std::endl;

    if (str.getLength() == 0) {
        std::cout << "length is zero" << std::endl;
    }

    std::cout << "-> Checking if the string is empty or not." << std::endl;

    if (str.isEmpty()) {
        std::cout << "string is empty" << std::endl;
    }

    std::cout << "-> Checking if the string is palindrome or not." << std::endl;

    if (str.isPalindrome()) {
        std::cout << "string is palindrome" << std::endl;
    }

    std::cout << "-> Printing the string." << std::endl;

    str.print(true);

    return 0;
}
