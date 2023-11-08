#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence1;
    std::unordered_map<int, int> frequency;

    // Чтение первой последовательности и добавление элементов в sequence1
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        sequence1.push_back(num);
        frequency[num]++;
    }

    // Второй проход для второй последовательности и вывод пересечения
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        if (frequency.find(num) != frequency.end() && frequency[num] > 0) {
            std::cout << num << " ";
            frequency[num]--;
        }
    }
    std::cout << std::endl;

    return 0;
}
