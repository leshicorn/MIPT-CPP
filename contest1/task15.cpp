#include <iostream>
#include <string>
#include <stdlib.h>

bool is_digit(char num) {
    return (num >= '0' && num <= '9');
}

int main() {
    char buf;
    int amo = 0;
    while (std::cin >> buf && buf != '@') {
        
        if (is_digit(buf)) {
            amo++;
        }
    }
    std::cout << amo << std::endl;
}