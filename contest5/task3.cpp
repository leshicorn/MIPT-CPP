#include <iostream>
#include <algorithm>
#include <vector>

class SpacePort
{
public:
    std::vector<int> ports;
    SpacePort(unsigned int size) {
        ports.resize(size);
    }

    bool requestLanding(unsigned int dockNumber) {
        if (dockNumber >= ports.size()) {
            return false;
        }
        else if (ports[dockNumber] == 0) {
            ports[dockNumber] = 1;
            return true;
        }
        else {
            return false;
        }
    }

    bool requestTakeoff(unsigned int dockNumber) {
        if (dockNumber >= ports.size()) {
            return false;
        }
        else if (ports[dockNumber] == 1) {
            ports[dockNumber] = 0;
            return true;
        }
        else {
            return false;
        }
    }

    ~SpacePort() {
        ports.clear();
    }
};

int main() {

    SpacePort s(5);
    std::cout << std::boolalpha << s.requestLanding(0) << "\n";
    std::cout << std::boolalpha << s.requestLanding(4) << "\n";
    std::cout << std::boolalpha << s.requestLanding(5) << "\n";
    std::cout << std::boolalpha << s.requestTakeoff(0) << "\n";
    std::cout << std::boolalpha << s.requestTakeoff(4) << "\n";
    std::cout << std::boolalpha << s.requestTakeoff(5) << "\n";

    return 0;
}