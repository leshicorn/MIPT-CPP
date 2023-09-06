#include <iostream>

using namespace std;

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int prime(int number) {
    int cur_pos = 0;
    int prime_num = 2;
    int check_prime = 2;

    while (cur_pos != number) {
        if (is_prime(check_prime)) {
            cur_pos++;
            prime_num = check_prime;
        }
        check_prime++;
    }
    return prime_num;
}

int main() {
    int n = 0;
    cin >> n;
    cout << prime(n) << endl;
}