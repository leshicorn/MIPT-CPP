#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>

int main() {
    int N;
    std::cin >> N;

    std::unordered_map<std::string, int> wordCount;

    for (int i = 0; i < N; ++i) {
        std::string word;
        std::cin >> word;

        // Приведем слово к нижнему регистру
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        wordCount[word]++;
    }

    std::vector<std::pair<std::string, int>> result;

    // Найдем слова, встречающиеся более чем в двух вариантах написания
    for (const auto& pair : wordCount) {
        if (pair.second > 2) {
            result.push_back(std::make_pair(pair.first, pair.second));
        }
    }

    // Сортируем результат по количеству вариантов и по словарю
    std::sort(result.begin(), result.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    });

    // Выводим результат
    for (const auto& entry : result) {
        std::cout << entry.first << std::endl;
    }

    return 0;
}
