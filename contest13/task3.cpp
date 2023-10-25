#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <vector>

class Tracker {
private:
    std::unordered_map<std::string, std::vector<unsigned long long>> clickData;

public:
    void click(const std::string& username, unsigned long long timestamp) {
        // Добавляем клик пользователя с указанным временем.
        clickData[username].push_back(timestamp);
    }

    unsigned long long getClickCount(const std::string& username) const {
        // Возвращаем количество кликов пользователя.
        const auto it = clickData.find(username);
        if (it != clickData.end()) {
            return it->second.size();
        } else {
            return 0;
        }
    }

    #include <algorithm>

    unsigned long long getFirstClick(const std::string& username) const {
        // Возвращаем время первого клика пользователя.
        auto it = clickData.find(username);
        if (it != clickData.end() && !it->second.empty()) {
            return *std::min_element(it->second.begin(), it->second.end());
        } else {
            return std::numeric_limits<unsigned long long>::max();
        }
    }

    unsigned long long getLastClick(const std::string& username) const {
        // Возвращаем время последнего клика пользователя.
        auto it = clickData.find(username);
        if (it != clickData.end() && !it->second.empty()) {
            return *std::max_element(it->second.begin(), it->second.end());
        } else {
            return std::numeric_limits<unsigned long long>::min();
        }
    }
};

int main() {
    Tracker t;
    t.click("alice", 1000);
    t.click("bob", 1100);
    t.click("alice", 1001);
    t.click("alice", 1200);
    t.click("alice", 1002);

    std::cout << t.getClickCount("alice") << std::endl;
    std::cout << t.getClickCount("bob") << std::endl;
    std::cout << t.getFirstClick("alice") << std::endl;
    std::cout << t.getFirstClick("bob") << std::endl;
    std::cout << t.getLastClick("alice") << std::endl;
    std::cout << t.getLastClick("bob") << std::endl;

    return 0;
}
