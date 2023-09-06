#include <iostream>

using namespace std;

void dividers(int num) {
    for (int i = 1; i <= num; i++) {
        if (num % i == 0)
            cout << i << " ";
    }
    cout << endl;
}

int main() {
    int num = 0;
    cin >> num;
    dividers(num);

    return 0;
}