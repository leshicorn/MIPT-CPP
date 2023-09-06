#include <iostream>

using namespace std;

void binary(unsigned int n) {
    if (n == 0) 
        return;
    binary(n / 2);
    cout << n % 2;
}

int main() {
    unsigned int n;
    cin >> n;
    binary(n);
    cout << endl;
    return 0;
}