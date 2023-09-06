#include <iostream>

using namespace std;
unsigned int sum_of_numbers(unsigned long long int n);
unsigned long long int factorial(unsigned int n);
//----------------------------------------------------
unsigned int sum_of_numbers(unsigned long long int n) {
    unsigned int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

unsigned long long int factorial(unsigned int n) {
    unsigned long long int fact = 1;
    if (n == 0) {
        return 1;
    }
    else {
        for (unsigned int i = 1; i <= n; i++) {
            fact *= i;
        }
    }
    return fact;
}

int main() {
    unsigned int n;
    cin >> n;
    cout << sum_of_numbers(factorial(n)) << endl;
    return 0;
}