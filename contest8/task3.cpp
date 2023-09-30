#include <iostream>

class Animal {
public:
    // Погладить данную зверушку.
    // Последствия зависят от реализации данного метода для класса конкретной зверушки.
    virtual void pet() = 0;
    virtual ~Animal() {}
};

class NPC {
public:
    // Поговорить с NPC.
    // Что он скажет - зависит от реализации данного метода для конкретного NPC.
    virtual void talk() = 0;
    virtual ~NPC() {}
};

class SmartCat : public Animal, public NPC {
public:
    // Переопределение метода для интерфейса Animal.
    void pet() override {
        std::cout << "Meow!" << std::endl;
    }

    // Переопределение метода для интерфейса NPC.
    void talk() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // Пример использования SmartCat как Animal.
    Animal *a = new SmartCat();
    a->pet();
    delete a;

    // Пример использования SmartCat как NPC.
    NPC *n = new SmartCat();
    n->talk();
    delete n;

    return 0;
}
