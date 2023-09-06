#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unsigned int get_a_hexadecimal() {
    std::string number;
    cin >> number;
    std::unordered_map<char, int> avail;
    for (int i = 0; i < 10; i++) {
        avail[static_cast<char>('0' + i)] = i;
    }
    for (int i = 0; i < 6; i++) {
        avail[static_cast<char>(i + 'A')] = 10 + i;
    }
    int64_t deg = 1;
    unsigned int result = 0;
    for (int i = number.size() - 1; i >= 0; i--) {
        if (avail.find(number[i]) == avail.end()) {
            return 0;
        }
        result += (avail[number[i]] * deg);
        deg *= 16;
    }
    return result;
}

int main() {
    cout << get_a_hexadecimal() <<endl;
    return 0;
}