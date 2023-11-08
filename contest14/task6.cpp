#include <iostream>
#include <vector>
#include <algorithm>

bool isEven(int num) {
    return num % 2 == 0;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence;
    std::vector<int> even, odd;

    // Считываем последовательность и разделяем на четные и нечетные
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        sequence.push_back(num);
        if (isEven(num)) {
            even.push_back(num);
        } else {
            odd.push_back(num);
        }
    }

    // Сортируем четные по убыванию
    std::sort(even.rbegin(), even.rend());

    // Сортируем нечетные по возрастанию
    std::sort(odd.begin(), odd.end());

    // Восстанавливаем последовательность с отсортированными четными и нечетными
    for (int i = 0, j = 0, k = 0; i < n; i++) {
        if (isEven(sequence[i])) {
            sequence[i] = even[j];
            j++;
        } else {
            sequence[i] = odd[k];
            k++;
        }
    }

    // Выводим результат
    for (int num : sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
