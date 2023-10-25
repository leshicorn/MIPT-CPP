#include <iostream>
#include <vector>

using namespace std;

class Car {
protected:
    bool allowsBoarding;
    bool allowsLoading;
    unsigned int numberOfSeats;
    unsigned int numberOfContainers;

public:
    Car(bool allowsBoarding, bool allowsLoading, unsigned int numberOfSeats, unsigned int numberOfContainers)
        : allowsBoarding(allowsBoarding), allowsLoading(allowsLoading), numberOfSeats(numberOfSeats), numberOfContainers(numberOfContainers) {}

    bool isBoardingAllowed() const {
        return allowsBoarding;
    }

    bool isLoadingAllowed() const {
        return allowsLoading;
    }

    unsigned int getNumberOfSeats() const {
        return numberOfSeats;
    }

    unsigned int getNumberOfContainers() const {
        return numberOfContainers;
    }
};

class ConvoyManager {
private:
    vector<Car> cars;

public:
    void registerCar(const Car& c) {
        cars.push_back(c);
    }

    unsigned int getTotalSeats() const {
        unsigned int totalSeats = 0;
        for (const Car& car : cars) {
            if (car.isBoardingAllowed()) {
                totalSeats += car.getNumberOfSeats();
            }
        }
        return totalSeats;
    }

    unsigned int getTotalContainers() const {
        unsigned int totalContainers = 0;
        for (const Car& car : cars) {
            if (car.isLoadingAllowed()) {
                totalContainers += car.getNumberOfContainers();
            }
        }
        return totalContainers;
    }
};

int main() {
    ConvoyManager cm;
    Car c1(true, false, 12, 3);
    cm.registerCar(c1);
    Car c2(false, true, 12, 3);
    cm.registerCar(c2);
    Car c3(true, true, 12, 3);
    cm.registerCar(c3);
    Car c4(false, false, 12, 3);
    cm.registerCar(c4);

    cout << "Total available seats: " << cm.getTotalSeats() << endl;
    cout << "Total available containers: " << cm.getTotalContainers() << endl;

    return 0;
}
