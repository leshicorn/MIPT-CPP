#include <iostream>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::set<int> set1, set2, intersection;

    // Чтение первой последовательности и добавление элементов в set1
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        set1.insert(num);
    }

    // Чтение второй последовательности и проверка на пересечение с set1
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        if (set1.count(num) > 0) {
            intersection.insert(num);
        }
    }

    // Вывод пересечения в порядке возрастания
    for (int num : intersection) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
