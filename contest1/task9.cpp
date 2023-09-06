#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    int amount = 0;
    cin >> line;
    for (int i = 0; i < (int)line.length(); i++) {
        if (line[i] == '1') {
            amount++;
        }
    }

    cout << amount << endl;
}