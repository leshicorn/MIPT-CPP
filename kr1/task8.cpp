#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    std::map<std::string, std::vector<int>> data;

    for (int i = 0; i < N; ++i) {
        std::string sensorName;
        int sensorValue;
        std::cin >> sensorName >> sensorValue;
        data[sensorName].push_back(sensorValue);
    }

    // Сортировка значений для каждого датчика
    for (auto& entry : data) {
        std::sort(entry.second.begin(), entry.second.end());
    }

    int M;
    std::cin >> M;

    for (int i = 0; i < M; ++i) {
        std::string queryName;
        std::cin >> queryName;

        if (data.find(queryName) != data.end()) {
            // Если датчик найден, найдем медианное значение
            std::vector<int>& values = data[queryName];
            int medianIndex = (values.size() - 1) / 2;

            // Медианное значение для массива четной длины - меньшее из двух центральных элементов
            int medianValue = values[medianIndex];

            std::cout << medianValue << std::endl;
        } else {
            std::cout << "no data" << std::endl;
        }
    }

    return 0;
}