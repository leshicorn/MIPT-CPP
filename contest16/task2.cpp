#include <iostream>
#include <vector>
#include <string>

class Connector {
public:
    Connector(const std::string& address) {
        // Здесь может быть код инициализации соединения.
        // Например, бросаем исключение, если адрес пустой.
        if (address.empty()) {
            throw std::invalid_argument("Empty address");
        }
        std::cout << "Connecting to " << address << std::endl;
    }

    void sendRequest(const std::string& data) {
        // Здесь может быть код отправки сообщения.
        // Например, бросаем исключение, если сообщение пустое.
        if (data.empty()) {
            throw std::invalid_argument("Empty message");
        }
        std::cout << "Sending request: " << data << std::endl;
        // Здесь можно бросить исключение, если отправка не удалась.
        // Например, бросаем std::runtime_error("Connection error");
    }
};

int main() {
    try {
        int N;
        std::cout << "Enter the number of addresses: ";
        std::cin >> N;

        std::vector<std::string> addresses(N);
        std::cout << "Enter the addresses:" << std::endl;
        for (int i = 0; i < N; ++i) {
            std::cin >> addresses[i];
        }

        for (const auto& address : addresses) {
            try {
                Connector connector(address);
                connector.sendRequest("HELLO");
                std::cout << address << ": ok" << std::endl;
            } catch (const std::exception& e) {
                std::cout << address << ": " << e.what() << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
