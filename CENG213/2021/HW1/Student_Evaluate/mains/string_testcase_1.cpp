#include <iostream>

#include "String.h"
//#include "../String.h"

/*
 * Case 1 : Default constructor; print.
 */
int main() {
    std::cout << "-> Creating a string with default constructor." << std::endl;

    String str;

    std::cout << "-> Printing the string." << std::endl;

    str.print(true);

    return 0;
}
