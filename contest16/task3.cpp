#include <iostream>
#include <vector>
#include <memory>

class Brain {
protected:
    std::vector<double> data;
    std::string phrase;

public:
    Brain() {
        data.resize(1000000);
        phrase = "Booyahg Booyahg Booyahg";
    }

    std::string speak() {
        return phrase;
    }
};

class Goblin {
private:
    std::shared_ptr<Brain> brain;

public:
    // Конструктор, принимающий shared_ptr на мозг
    Goblin(const std::shared_ptr<Brain>& goblinBrain) : brain(goblinBrain) {}

    // Метод для получения фразы от мозга
    std::string speak() {
        return brain->speak();
    }
};

// Функция для создания армии гоблинов с общим мозгом
std::vector<Goblin> create_goblin_army(unsigned int size) {
    std::shared_ptr<Brain> armyBrain = std::make_shared<Brain>();
    std::vector<Goblin> army;
    army.reserve(size);

    for (unsigned int i = 0; i < size; ++i) {
        army.emplace_back(armyBrain);
    }

    return army;
}

int main() {
    unsigned int size1 = 1;
    unsigned int size2 = 10;

    std::vector<Goblin> army1 = create_goblin_army(size1);
    std::vector<Goblin> army2 = create_goblin_army(size2);

    for (unsigned int i = 0; i < size1; ++i) {
        std::cout << army1[i].speak() << std::endl;
    }

    for (unsigned int i = 0; i < size2; ++i) {
        std::cout << army2[i].speak() << std::endl;
    }

    return 0;
}
