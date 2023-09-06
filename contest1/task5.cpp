#include <iostream>

using namespace std;

int main() {
    int width = 0, height = 0;

    cin >> height >> width;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1)
                cout << "+";
            else {
                if (j == width - 1 || j == 0)
                    cout << "+";
                else
                    cout << " ";
            }
    }
    cout << endl;
    }
}