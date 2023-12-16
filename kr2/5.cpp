#include <iostream>
#include <stdexcept>

using namespace std;

class GasStation {
public:
    GasStation(unsigned int capacity) : capacity(capacity), current_fuel(0) {
        std::cout << "Creating gas station, capacity: " << capacity << std::endl;
    }

    void fill(unsigned int fill_amo) {
        if (current_fuel + fill_amo > capacity) {
            std::cout << "Trying to fill " << fill_amo << std::endl;
            std::cout << "Failed to fill" << std::endl;
            std::cout << "Fuel limit after the action is " << current_fuel << std::endl;
            // throw std::exception();
            
        }
        else {
            current_fuel += fill_amo;
            std::cout << "Trying to fill " << fill_amo << std::endl;
            std::cout << "Fuel limit after the action is " << current_fuel << std::endl;
        }
    }

    void tank(unsigned int tank_amo) {
        if (current_fuel < tank_amo) {
            std::cout << "Trying to tank " << tank_amo << std::endl;
            std::cout << "Failed to tank" << std::endl;
            std::cout << "Fuel limit after the action is " << current_fuel << std::endl;
            // throw std::exception();
        }
        else {
            current_fuel -= tank_amo;
            std::cout << "Trying to tank " << tank_amo << std::endl;
            std::cout << "Fuel limit after the action is " << current_fuel << std::endl;
        }
    }

    unsigned int get_limit() const {
        return current_fuel;
    }

private:
    unsigned int capacity;
    unsigned int current_fuel;
};

int main() {
    int init = 0;
    cin >> init;
    GasStation s = GasStation(init);
    int number_actions = 0;
    cin >> number_actions;

    for (int i = 0; i < number_actions; ++i) {
        string action;
        int value;
        cin >> action >> value;
        try {
            if (action == "fill") {
                s.fill(value);
            } else if (action == "tank") {
                s.tank(value);
            } else {
                std::cout << "Unknown action" << std::endl;
            }
        } catch (std::exception &e) {
            std::cout << "Exception caught" << std::endl;
        }
    }
}