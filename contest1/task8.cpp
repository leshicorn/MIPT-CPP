#include <iostream>

using namespace std;

int main() {
    int height = 0;
    cin >> height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "+";
        }
        cout << endl;
    }
}