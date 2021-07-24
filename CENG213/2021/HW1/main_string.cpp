#include <iostream>

#include "String.h"

int main() {
    std::cout << "-> Creating a string with default constructor." << std::endl;

    String str1;

    std::cout << "-> Printing the string." << std::endl;

    str1.print(true);

    std::cout << "-> Creating a string with default constructor." << std::endl;

    char chr[] = "data structures";
    String str2(chr);

    std::cout << "-> Printing the string." << std::endl;

    str2.print(true);

    return 0;
}
