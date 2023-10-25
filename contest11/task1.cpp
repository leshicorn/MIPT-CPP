#include <iostream>

template <typename T>
T get_min_value(const T &a, const T &b) {
    return (a < b) ? a : b;
}

int main() {
    int a = 5;
    int b = 4;
    std::string s1 = "abc";
    std::string s2 = "zxc";
    
    std::cout << "Min int: " << get_min_value(a, b) << std::endl;
    std::cout << "Min string: " << get_min_value(s1, s2) << std::endl;
    
    return 0;
}
