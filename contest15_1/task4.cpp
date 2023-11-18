#include <iostream>
#include <vector>
#include <stdexcept>

class Ball {
public:
    // Конструктор
    Ball() : state(State::Whole) {}

    // Попытка сломать шар.
    void destroy() {
        if (state == State::Whole) {
            state = State::Broken;
            std::cout << "Break attempt #" << breakAttempts << ", trying to break ball " << id << ": success!\n";
            breakAttempts++;
        } else {
            throw std::exception();
        }
    }

    // Попытка потерять шар.
    void lose() {
        if (state == State::Whole) {
            state = State::Lost;
            std::cout << "Lose attempt #" << loseAttempts << ", trying to lose ball " << id << ": success!\n";
            loseAttempts++;
        } else {
            throw std::exception();
        }
    }

    // Установка идентификатора шара
    void setId(int ballId) {
        id = ballId;
    }

private:
    enum class State {
        Whole,
        Broken,
        Lost
    };

    State state;
    int id;
    static int breakAttempts;
    static int loseAttempts;
};

// Инициализация статических переменных
int Ball::breakAttempts = 0;
int Ball::loseAttempts = 0;

int main() {
    int n, breakIndex, loseIndex;
    std::cin >> n >> breakIndex >> loseIndex;

    // Создаем вектор шаров
    std::vector<Ball> balls(n);

    // Устанавливаем идентификаторы шаров
    for (int i = 0; i < n; ++i) {
        balls[i].setId(i);
    }

    try {
        // Пытаемся сломать и потерять шары в соответствии с вводом
        balls[breakIndex].destroy();
        balls[loseIndex].lose();
    } catch (const std::exception&) {
        std::cerr << "Exception: Attempt to break or lose an already broken or lost ball!\n";
    }

    return 0;
}
