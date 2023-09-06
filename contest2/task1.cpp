#include <iostream>

using namespace std;

bool is_simple(int num) {

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (is_simple(i)) {
            cout <<i <<' ';
        }
    }
    cout << endl;
    return 0;
}