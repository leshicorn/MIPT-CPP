#include <iostream>
#include <algorithm>
#include <vector>

class CalendarData {
public:
    int year;
    int month;
    int day;
    CalendarData(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    ~CalendarData() {
        std::cout << this->year << "." << this->month << "." << this->day << std::endl;
    }
};

int main() {

    CalendarData data(3, 3, 333);
    return 0;
}