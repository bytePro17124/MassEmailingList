#ifndef HELPERFUNCTIONS
#define HELPERFUNCTIONS

#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>
#include <vector>
#include <list>

template<class T>
T getNumber(const std::string& message, const T& a, const T& b) {
    T goodn = 0;
    while ((std::cout << message && !(std::cin >> goodn)) || (goodn < a || goodn > b)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid, try again.\n";
    }
    return goodn;
};

void simpleClearScreen();

char getYorN(const std::string&);

void pressEnterToContinue();


#endif // HELPERFUNCTIONS

