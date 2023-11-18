#include <iostream>
#include <unordered_map>

int main() {
    int N;
    std::cin >> N;

    std::unordered_map<int, int> countMap;

    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;
        countMap[num]++;
    }

    int maxUnique = -1;

    for (const auto& pair : countMap) {
        if (pair.second == 1 && pair.first > maxUnique) {
            maxUnique = pair.first;
        }
    }

    std::cout << maxUnique << std::endl;

    return 0;
}
