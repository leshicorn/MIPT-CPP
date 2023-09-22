#include <iostream>
#include <algorithm>
#include <vector>

class Train {
public:
    double mass;
    double x;
    double current_speed;

    Train(double m) {
        mass = m;
    }

    void move(double dt) {
        x += current_speed * dt;
    }

    void accelerate(double dp) {
        current_speed += dp / mass;
    }

    double getX() {
        return x;
    }

    ~Train() {
        std::cout << "Train deleted" << std::endl;
    }
};

void TestTrain() {
    Train t(10);
    t.accelerate(1); // Скорость стала 0.1
    t.move(1);
    std::cout << "Current X: " << t.getX() << "\n";
    t.move(1);
    std::cout << "Current X: " << t.getX() << "\n";
    t.accelerate(-2); // Скорость стала -0.1
    t.move(3);
    std::cout << "Current X: " << t.getX() << "\n";
}

int main() {

    TestTrain();
    
    return 0;
}