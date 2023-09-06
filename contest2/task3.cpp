#include <iostream>

using namespace std;

unsigned int sum_of_numbers(unsigned int n) {
    int res = 0;
    while (n > 0) {
        res += (n % 10);
        n /= 10;
    }
    return res;
}


int main() {
    unsigned int n;
    cin >> n;
    cout << sum_of_numbers(n) << endl;
    return 0;
}