#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

struct Event {
    unsigned int timestamp;
    std::string action;
    std::string property;
    std::string value;
};

struct ObjectState {
    std::map<std::string, std::string> properties;
};

int main() {
    int N, M;
    std::cin >> N;

    std::vector<Event> events(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> events[i].timestamp >> events[i].action >> events[i].property;
        if (events[i].action == "SET") {
            std::cin >> events[i].value;
        }
    }

    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        unsigned int queryTimestamp;
        std::cin >> queryTimestamp;

        ObjectState currentState;
        for (const auto& event : events) {
            if (event.timestamp > queryTimestamp) {
                break;
            }

            if (event.action == "SET") {
                currentState.properties[event.property] = event.value;
            } else if (event.action == "DELETE") {
                currentState.properties.erase(event.property);
            }
        }

        // Выводим текущее состояние объекта для данного момента времени
        for (const auto& [property, value] : currentState.properties) {
            std::cout << property << " : " << value << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}
