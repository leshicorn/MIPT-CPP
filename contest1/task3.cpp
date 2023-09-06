#include <iostream>

using namespace std;

int main() {
    int width = 0, height = 0;

    cin >> height >> width;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << "+";
    }
    cout << endl;
    }
}