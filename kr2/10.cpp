#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <forward_list>
#include <string.h>
#include <ctype.h>
#include <cstdlib>

using namespace std;

class Truck {
public:
    int capacity;
    int speed;
    string number;
    // Конструктор:
    // - capacity - грузоподъемность
    // - speed - скорость
    // - number - номер (да, это строка)
    Truck(unsigned int cap, unsigned int sp, const std::string& num) {
        capacity = cap;
        speed = sp;
        number = num;
    }
    // Дополнительные методы и операторы, которые потребуются

    //Перегрузка оператора вывода "<<" для вывода number, capacity, speed.
    friend ostream &operator<<(std::ostream& os, const Truck& T) {
        os << T.number << ' ' << T.capacity << ' ' << T.speed;
        return os;
    }
    
    
};

int main() {
    vector<Truck> data;
    data.push_back(Truck(10, 10, "a720po"));
    data.push_back(Truck(100, 10, "a721aa"));
    data.push_back(Truck(100, 20, "e721op"));
    data.push_back(Truck(10, 10, "o720po"));
    for(const Truck& c : data) {
        cout << c << endl;
    }
    return 0;
}