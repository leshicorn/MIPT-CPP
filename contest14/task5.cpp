#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence;

    // Считываем последовательность
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        sequence.push_back(num);
    }

    int k;
    std::cin >> k;

    // Удаляем элементы, которые больше k
    for (int i = 0; i < sequence.size(); ) {
        if (sequence[i] > k) {
            sequence.erase(sequence.begin() + i);
        } else {
            i++;
        }
    }

    // Выводим результат
    for (int num : sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
