#include "io.h"
#include <iostream>

int readNumber() {
    int num{ };
    std::cout << "Please enter an integer: ";
    std::cin >> num;

    return num;
}

void writeAnswer(int num) {
    std::cout << num << '\n';
}
