#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

// Функция-компаратор для сортировки по убыванию длины слов
bool compareByLength(const std::string& a, const std::string& b) {
    return a.length() > b.length();
}

int main() {
    int N;
    std::cin >> N;

    std::set<std::string> uniqueWords;
    
    for (int i = 0; i < N; ++i) {
        std::string word;
        std::cin >> word;
        uniqueWords.insert(word);
    }

    // Создаем вектор и копируем уникальные слова из множества
    std::vector<std::string> sortedWords(uniqueWords.begin(), uniqueWords.end());

    // Сортируем слова, передавая функцию-компаратор compareByLength
    std::sort(sortedWords.begin(), sortedWords.end(), compareByLength);

    // Выводим отсортированные уникальные слова
    for (const std::string& word : sortedWords) {
        std::cout << word << '\n';
    }

    return 0;
}
