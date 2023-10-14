#include <iostream>

// Абстрактное транспортное средство
class Vehicle {
public:
    // Может ли ездить по суше
    virtual bool canDrive() const {
        return false;
    }
    // Может ли плавать
    virtual bool canSail() const {
        return false;
    }
    // Может ли летать
    virtual bool canFly() const {
        return false;
    }
    virtual ~Vehicle() {};
};

// Автомобиль
class Car : public Vehicle {
public:
    // Может ездить по суше
    bool canDrive() const override {
        return true;
    }
};

// Корабль
class Ship : public Vehicle {
public:
    // Может плавать
    bool canSail() const override {
        return true;
    }
};

// Самолёт
class Plane : public Vehicle {
public:
    // Может летать
    bool canFly() const override {
        return true;
    }
};

// Грузовик (наследует от автомобиля)
class Truck : public Car {
public:
    // Может ездить по суше
    // Полностью наследует поведение Car
};

int main() {
    std::cout << std::boolalpha;
    Vehicle* v;
    
    v = new Car();
    std::cout << "Testing Car" << std::endl;
    std::cout << "Car can drive: " << v->canDrive() << std::endl;
    std::cout << "Car can sail: " << v->canSail() << std::endl;
    std::cout << "Car can fly: " << v->canFly() << std::endl;
    delete v;

    v = new Ship();
    std::cout << "Testing Ship" << std::endl;
    std::cout << "Ship can drive: " << v->canDrive() << std::endl;
    std::cout << "Ship can sail: " << v->canSail() << std::endl;
    std::cout << "Ship can fly: " << v->canFly() << std::endl;
    delete v;

    v = new Plane();
    std::cout << "Testing Plane" << std::endl;
    std::cout << "Plane can drive: " << v->canDrive() << std::endl;
    std::cout << "Plane can sail: " << v->canSail() << std::endl;
    std::cout << "Plane can fly: " << v->canFly() << std::endl;
    delete v;

    Car* c = new Truck();
    std::cout << "Testing Truck" << std::endl;
    std::cout << "Truck can drive: " << c->canDrive() << std::endl;
    std::cout << "Truck can sail: " << c->canSail() << std::endl;
    std::cout << "Truck can fly: " << c->canFly() << std::endl;
    delete c;

    return 0;
}
