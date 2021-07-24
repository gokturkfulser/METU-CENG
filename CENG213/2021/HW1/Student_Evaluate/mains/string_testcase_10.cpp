#include <iostream>

#include "String.h"
//#include "../String.h"

/*
 * Case 10 : String constructor; operator<; print.
 */
int main() {
    std::cout << "-> Creating some strings with string constructor." << std::endl;

    char chr1[] = "a";
    String str1(chr1);
    char chr2[] = "aa";
    String str2(chr2);
    char chr3[] = "ab";
    String str3(chr3);
    char chr4[] = "aba";
    String str4(chr4);
    char chr5[] = "abc";
    String str5(chr5);
    char chr6[] = "saippuakivikauppias";
    String str6(chr6);
    char chr7[] = "eva can i see bees in a cave";
    String str7(chr7);

    std::cout << "-> Comparing the strings." << std::endl;

    std::cout << "is \"a\" < \"aa\"? " << (str1 < str2 ? "yes" : "no") << std::endl;
    std::cout << "is \"ab\" < \"aa\"? " << (str3 < str2 ? "yes" : "no") << std::endl;
    std::cout << "is \"aa\" < \"aba\"? " << (str2 < str4 ? "yes" : "no") << std::endl;
    std::cout << "is \"abc\" < \"aba\"? " << (str5 < str4 ? "yes" : "no") << std::endl;
    std::cout << "is \"aba\" < \"saippuakivikauppias\"? " << (str4 < str6 ? "yes" : "no") << std::endl;
    std::cout << "is \"saippuakivikauppias\" < \"eva can i see bees in a cave\"? " << (str6 < str7 ? "yes" : "no") << std::endl;

    std::cout << "-> Printing the strings." << std::endl;

    str1.print(true);
    str2.print(true);
    str3.print(true);
    str4.print(true);
    str5.print(true);
    str6.print(true);
    str7.print(true);

    return 0;
}
