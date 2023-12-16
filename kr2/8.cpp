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
            throw std::logic_error("Attempt to break an already broken or lost ball!");
        }
    }

    // Попытка потерять шар.
    void lose() {
        if (state == State::Whole) {
            state = State::Lost;
            std::cout << "Lose attempt #" << loseAttempts << ", trying to lose ball " << id << ": success!\n";
            loseAttempts++;
        } else {
            throw std::logic_error("Attempt to lose an already broken or lost ball!");
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
    int n;
    std::cin >> n;
    std::vector<int> ids(n);
    for (int i = 0; i < n; i++) {
        std::cin >> ids[i];
    }

    // Создаем вектор шаров
    std::vector<Ball> balls(n);

    // Устанавливаем идентификаторы шаров
    for (int i = 0; i < n; ++i) {
        balls[i].setId(ids[i]);
    }


    for (int i = 0; i < n; ++i) {
        int action;
        std::cin >> action;
        switch (action) {
        case 0:
            balls[i].destroy();
            break;
        case 1:
            balls[i].lose();
            break;        
        default:
            break;
        }
    }

    // try {
    //     // Пытаемся сломать и потерять шары в соответствии с вводом
    //     balls[id_1].destroy();
    //     balls[id_2].lose();
    // } catch (const std::logic_error& e) {
    //     std::cerr << "Logic Error: " << e.what() << "\n";
    // }

    // balls[0].destroy();
    // balls[1].lose();

    return 0;
}
