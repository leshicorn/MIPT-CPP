#include <iostream>
#include <string>

using namespace std;

// Объявление класса Item
class Item {
public:
    // Конструктор для создания предмета
    Item(string title, int weight, int level, bool magical)
        : title(title), weight(weight), level(level), magical(magical) {}

    // Получить вес предмета
    int getWeight() {
        return weight;
    }

    // Получить уровень предмета
    int getLevel() {
        return level;
    }

    // Проверить, является ли предмет магическим
    bool isMagical() {
        return magical;
    }

private:
    string title;
    int weight;
    int level;
    bool magical;
};

// Объявление базового класса Player
class Player {
protected:
    int strength;
    int level;

public:
    Player() : strength(0), level(0) {}

    virtual ~Player() {}

    void setStrength(int strength) {
        this->strength = strength;
    }

    void setLevel(int level) {
        this->level = level;
    }

    int getStrength() {
        return strength;
    }

    int getLevel() {
        return level;
    }

    virtual bool canUse(Item* item) = 0;
};

// Реализация класса Knight
class Knight : public Player {
public:
    // Переопределение метода canUse для рыцаря
    bool canUse(Item* item) override {
        if (!item->isMagical() && strength >= item->getWeight() && level >= item->getLevel()) {
            return true;
        }
        return false;
    }
};

// Реализация класса Wizard
class Wizard : public Player {
public:
    // Переопределение метода canUse для волшебника
    bool canUse(Item* item) override {
        if (strength >= item->getWeight() && level >= item->getLevel()) {
            return true;
        }
        return false;
    }
};

int main() {
    Item* items[3];
    items[0] = new Item("Small sword", 1, 1, false);
    items[1] = new Item("Big sword", 5, 3, false);
    items[2] = new Item("Ward", 1, 3, true);

    Player* players[2];
    players[0] = new Wizard();
    players[0]->setStrength(3);
    players[0]->setLevel(5);
    players[1] = new Knight();
    players[1]->setStrength(6);
    players[1]->setLevel(5);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Can use: " << players[i]->canUse(items[j]) << endl;
        }
    }

    // Очистка памяти
    for (int i = 0; i < 3; i++) {
        delete items[i];
    }

    for (int i = 0; i < 2; i++) {
        delete players[i];
    }

    return 0;
}
