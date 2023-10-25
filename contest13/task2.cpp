#include <iostream>
#include <string>
#include <unordered_set>

class SessionManager {
private:
    std::unordered_set<std::string> activeUsers;

public:
    void login(const std::string& username) {
        // Вход пользователя - добавляем его в множество активных пользователей.
        activeUsers.insert(username);
    }

    void logout(const std::string& username) {
        // Выход пользователя - удаляем его из множества активных пользователей.
        activeUsers.erase(username);
    }

    int getNumberOfActiveUsers() const {
        // Возвращаем размер множества активных пользователей, который равен количеству активных пользователей.
        return activeUsers.size();
    }
};

int main() {
    SessionManager m;
    m.login("alice");
    std::cout << m.getNumberOfActiveUsers() << std::endl;
    m.login("bob");
    std::cout << m.getNumberOfActiveUsers() << std::endl;
    m.login("alice");
    std::cout << m.getNumberOfActiveUsers() << std::endl;
    m.logout("whoever");
    std::cout << m.getNumberOfActiveUsers() << std::endl;
    m.logout("alice");
    std::cout << m.getNumberOfActiveUsers() << std::endl;
    m.logout("bob");
    std::cout << m.getNumberOfActiveUsers() << std::endl;

    return 0;
}
