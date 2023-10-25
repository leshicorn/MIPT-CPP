#include <iostream>
#include <string>
#include <unordered_map>

class Animal {
public:
    virtual std::string getType() const = 0;
    virtual ~Animal() {}
};

class Monkey : public Animal {
public:
    std::string getType() const override {
        return "monkey";
    }
};

class Lion : public Animal {
public:
    std::string getType() const override {
        return "lion";
    }
};

class ZooKeeper {
private:
    std::unordered_map<std::string, int> animalCounts;

public:
    ZooKeeper() {}

    void handleAnimal(const Animal& a) {
        const std::string type = a.getType();
        // Используем оператор [] для увеличения счетчика типа животного.
        animalCounts[type]++;
    }

    int getAnimalCount(const std::string& type) const {
        // Ищем количество животных данного типа в контейнере.
        auto it = animalCounts.find(type);
        if (it != animalCounts.end()) {
            return it->second;
        } else {
            return 0; // Таких животных не было обработано.
        }
    }
};

int main() {
    ZooKeeper z;
    Animal* a = new Monkey();
    z.handleAnimal(*a);
    delete a;
    a = new Monkey();
    z.handleAnimal(*a);
    delete a;
    a = new Lion();
    z.handleAnimal(*a);
    delete a;
    
    std::cout << z.getAnimalCount("monkey") << std::endl;
    std::cout << z.getAnimalCount("lion") << std::endl;
    std::cout << z.getAnimalCount("cat") << std::endl;

    return 0;
}
