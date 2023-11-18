#include <iostream>
#include <stdexcept>

class GasStation {
public:
    GasStation(unsigned int capacity) : capacity(capacity), fuelLimit(0) {
        std::cout << "Creating gas station, capacity: " << capacity << std::endl;
    }

    void fill(unsigned int n) {
        if (fuelLimit + n > capacity) {
            std::cout << "Trying to fill " << n << std::endl;
            std::cout << "Failed to fill" << std::endl;
            throw std::exception();
        }
        fuelLimit += n;
        std::cout << "Trying to fill " << n << std::endl;
        std::cout << "Fuel limit after the action is " << fuelLimit << std::endl;
    }

    void tank(unsigned int n) {
        if (fuelLimit < n) {
            std::cout << "Trying to tank " << n << std::endl;
            std::cout << "Failed to tank" << std::endl;
            throw std::exception();
        }
        fuelLimit -= n;
        std::cout << "Trying to tank " << n << std::endl;
        std::cout << "Fuel limit after the action is " << fuelLimit << std::endl;
    }

    unsigned int get_limit() const {
        return fuelLimit;
    }

private:
    unsigned int capacity;
    unsigned int fuelLimit;
};

int main() {
    try {
        GasStation s = GasStation(1000);
        s.fill(2000);
    } catch (const std::exception&) {
        // Handle exception
    }

    GasStation s = GasStation(1000);
    s.fill(300);
    std::cout << s.get_limit() << std::endl;
    s.tank(100);
    s.fill(300);
    std::cout << s.get_limit() << std::endl;

    for (unsigned int i = 0; i < 5; i++) {
        s.tank(50);
    }
    std::cout << s.get_limit() << std::endl;

    try {
        s.fill(1000);
    } catch (const std::exception&) {
        // Handle exception
    }

    for (unsigned int i = 0; i < 50; i++) {
        try {
            s.tank(100);
        } catch (const std::exception&) {
            // Handle exception
        }
        std::cout << s.get_limit() << std::endl;
    }

    return 0;
}
