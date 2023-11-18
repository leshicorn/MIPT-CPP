#include <iostream>
#include <vector>

class MoneyBox {
public:
    // Конструктор и деструктор, если нужны
    MoneyBox() {}
    ~MoneyBox() {}

    // Добавить монетку достоинством value
    void addCoin(unsigned int value) {
        coins.push_back(value);
        std::cout << "Adding coin with value " << value << std::endl;
    }

    // Получить текущее количество монеток в копилке
    unsigned int getCoinsNumber() const {
        return coins.size();
    }

    // Получить текущее общее достоинство всех монеток
    unsigned int getCoinsValue() const {
        unsigned int totalValue = 0;
        for (const auto& coin : coins) {
            totalValue += coin;
        }
        return totalValue;
    }

private:
    std::vector<unsigned int> coins;
};

int main() {
    MoneyBox moneyBox;

    unsigned int numCoins;
    std::cout << "Enter the number of coins: ";
    std::cin >> numCoins;

    for (unsigned int i = 0; i < numCoins; ++i) {
        unsigned int coinValue;
        std::cout << "Enter the value of coin " << i + 1 << ": ";
        std::cin >> coinValue;
        moneyBox.addCoin(coinValue);
    }

    std::cout << "Number of coins: " << moneyBox.getCoinsNumber() << std::endl;
    std::cout << "Value of coins: " << moneyBox.getCoinsValue() << std::endl;

    return 0;
}
