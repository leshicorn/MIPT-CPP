#include <iostream>

using namespace std;

int main() {
    int n = 0;
    unsigned long long fact = 1;
    cin >> n;
    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }
    else {
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
    }
    cout << fact << endl;
}