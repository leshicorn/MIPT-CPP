#include <iostream>

namespace namespaceA {
class Engine {
public:
    void run() {
        std::cout << "EngineA run" << std::endl;
    }
};

}  // namespace namespaceA

namespace namespaceB {
class Engine {
public:
    void run() {
        std::cout << "EngineB run" << std::endl;
    }
};

}  // namespace namespaceB

namespace namespaceC {
class Engine {
public:
    void run() {
        std::cout << "EngineC run" << std::endl;
    }
};

}  // namespace namespaceC

class MyEngine {
private:
    namespaceA::Engine engineA;
    namespaceB::Engine engineB;
    namespaceC::Engine engineC;

public:
    void run(unsigned int number) {
        switch (number) {
            case 1:
                engineA.run();
                break;
            case 2:
                engineB.run();
                break;
            case 3:
                engineC.run();
                break;
            default:
                // Ничего не делать для других значений параметра
                break;
        }
    }
};

int main() {
    MyEngine e;
    e.run(1);  // вызов run из Engine-а из библиотеки A
    e.run(2);  // вызов run из Engine-а из библиотеки B
    e.run(3);  // вызов run из Engine-а из библиотеки C
    e.run(10); // ничего не происходит

    return 0;
}
