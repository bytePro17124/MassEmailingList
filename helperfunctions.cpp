#include "helperfunctions.h"

using namespace std;

void simpleClearScreen() {
    for (int i=0; i < 14; i++) {
        std::cout << "\n\n\n\n\n";
    }
}

char getYorN(const std::string& message) {
    char tmp;
    do
    {
        std::cout << message;
        std::cin >> tmp;
        tmp = toupper(tmp);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!(tmp == 'Y' || tmp == 'N'))
            std::cout << "Invalid, Try again (only takes 'Y', 'N', 'y', or 'n'.\n";

    } while (!(tmp == 'Y' || tmp == 'N'));
    return tmp;
}

void pressEnterToContinue() {
    std::cin.clear();
    std::cout << "\nPress 'ENTER' to continue.\n\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

