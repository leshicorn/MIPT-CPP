#include <iostream>
#include <string>

struct student {
    std::string name;
    std::string id_number_string;

    bool operator==(const student& other) const {
        return id_number_string == other.id_number_string;
    }
};

template<typename T>
bool check_them(T& x, T& y, T& z) {
    return x == y && y == z;
}

int main() {
    student a = {"Andy", "1234 123123"};
    student b = {"Andrew", "1234 123123"};
    student c = {"Andy", "1234123123"};
    
    std::cout << std::boolalpha << "Check result is: " << check_them(a, b, c) << std::endl;
    
    return 0;
}
