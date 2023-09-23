#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Объявление интерфейса Animal
class Animal {
public:
    virtual string getType() = 0;
    virtual bool isDangerous() = 0;
};

// Класс Monkey, который реализует интерфейс Animal
class Monkey : public Animal {
public:
    string getType() override {
        return "Monkey";
    }

    bool isDangerous() override {
        return false;
    }
};

// Класс Lion, который реализует интерфейс Animal
class Lion : public Animal {
public:
    string getType() override {
        return "Lion";
    }

    bool isDangerous() override {
        return true;
    }
};

// Класс ZooKeeper
class ZooKeeper {
private:
    int dangerousCount; // Число опасных зверей, которых обработал смотритель

public:
    ZooKeeper() : dangerousCount(0) {}

    // Метод для обработки зверя
    void handleAnimal(Animal* a) {
        if (a->isDangerous()) {
            dangerousCount++;
        }
        // Мы не управляем памятью для переданных объектов Animal, так как не знаем, кто и как их создал.
    }

    // Метод для получения числа обработанных опасных зверей
    int getDangerousCount() {
        return dangerousCount;
    }
};

int main() {
    ZooKeeper z;
    Monkey *m = new Monkey();
    z.handleAnimal(m);
    delete m;

    m = new Monkey();
    z.handleAnimal(m);
    delete m;

    Lion *l = new Lion();
    z.handleAnimal(l);
    delete l;

    cout << z.getDangerousCount() << endl; // Должно вывести 1

    return 0;
}
