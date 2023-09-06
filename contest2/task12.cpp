#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unsigned int get_really_any_hexadecimal() {
    std::string any_number;
    cin >> any_number;
    std::unordered_map<char, int> avail;
    for (int i = 0; i < 10; i++) {
        avail[static_cast<char>('0' + i)] = i;
    }
    for (int i = 0; i < 6; i++) {
        avail[static_cast<char>(i + 'A')] = 10 + i;
        avail[static_cast<char>(i + 'a')] = 10 + i;
    }
    std::string number;
    for (size_t i = 0; i < any_number.size();i++) {
        if (avail.find(any_number[i]) != avail.end()) {
            number.push_back(any_number[i]);
        }
    }
    int64_t deg = 1;
    unsigned int result = 0;
    for (int i = number.size() - 1; i >= 0; i--) {
        result += (avail[number[i]] * deg);
        deg *= 16;
    }
    return result;
}


int main() {
    
    cout <<get_really_any_hexadecimal() <<endl;
    return 0;
}