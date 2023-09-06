#include <iostream>

using namespace std;

char leveling(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 'a' + (c - 'A');
    }
}

int main() {
    char c;
    do {
        cin.get(c);
        cout << leveling(c);
    } while (c != '\n');
    cout << endl;
    return 0;
}