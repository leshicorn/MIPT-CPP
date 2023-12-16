#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct Cat {
    std::string name;
    unsigned int weight;

    Cat(const std::string& n, unsigned int w) : name(n), weight(w) {}
};

class BagOfCats {
public:
    // Конструктор и деструктор, если нужны
    BagOfCats() = default;
    ~BagOfCats() = default;

    // Сложить кота в мешок
    void putCat(const Cat& c) {
        cats.push_back(c);
    }

    // Распечатать статистику по содержимому мешка.
    void printStats() {
        // Сортировка котов по именам
        std::sort(cats.begin(), cats.end(), [](const Cat& a, const Cat& b) {
            return a.name < b.name;
        });

        // Группировка и вывод статистики
        std::unordered_map<std::string, std::pair<unsigned int, unsigned int>> catGroups;

        for (const auto& cat : cats) {
            auto& group = catGroups[cat.name];
            group.first++;
            group.second += cat.weight;
        }

        // Сортировка и вывод групп
        std::vector<std::pair<std::string, std::pair<unsigned int, unsigned int>>> groups(catGroups.begin(), catGroups.end());
        std::sort(groups.begin(), groups.end(), [](const auto& a, const auto& b) {
            if (a.second.first != b.second.first) {
                return a.second.first > b.second.first;
            }
            return a.second.second > b.second.second;
        });

        for (const auto& group : groups) {
            std::cout << group.first << " " << group.second.first << " " << group.second.second << std::endl;
        }
    }

private:
    std::vector<Cat> cats;
};

int main() {
    Cat cats[] = {{"Barsic", 1500}, {"Murzik", 1200}, {"Gav", 500}, {"Murzik", 1800}};
    BagOfCats bag;

    for (const auto& cat : cats)
        bag.putCat(cat);

    bag.printStats();

    return 0;
}
