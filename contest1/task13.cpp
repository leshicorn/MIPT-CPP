#include <iostream>

int findGCD(int num1, int num2) {
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int findLCM(int num1, int num2, int num3) {
    int gcd = findGCD(num1, num2);
    int lcm = (num1 * num2) / gcd;
    gcd = findGCD(lcm, num3);
    lcm = (lcm * num3) / gcd;
    return lcm;
}

int main() {
    int num1, num2, num3;
    std::cin >> num1 >> num2 >> num3;

    std::cout << findLCM(num1, num2, num3) << std::endl;

}