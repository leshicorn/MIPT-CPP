#include <iostream>

using namespace std;
unsigned int sum_of_numbers(unsigned long long int n);
unsigned long long int fibonacci(unsigned int n);
//----------------------------------------------------
unsigned int sum_of_numbers(unsigned long long int n) {
    unsigned int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}
//----------------------------------------------------
unsigned long long int fibonacci(unsigned int n) {
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (n >= 3)
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    unsigned int n;
    cin >> n;
    cout << sum_of_numbers(fibonacci(n)) << endl;
    return 0;
}