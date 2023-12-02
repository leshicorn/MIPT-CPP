#include <iostream>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class Queue {
private:
    Container container;

public:
    // Конструктор по умолчанию
    Queue() = default;

    // Константная функция front
    const T& front() const {
        return container.front();
    }

    // Неконстантная функция front
    T& front() {
        return container.front();
    }

    // Функция pop
    void pop() {
        container.pop_front();
    }

    // Функция push
    void push(const T& value) {
        container.push_back(value);
    }

    // Функция size
    size_t size() const {
        return container.size();
    }

    // Функция empty
    bool empty() const {
        return container.empty();
    }

    // Оператор ==
    bool operator==(const Queue& other) const {
        return container == other.container;
    }

    // Оператор !=
    bool operator!=(const Queue& other) const {
        return container != other.container;
    }
};

int main() {
    // Пример использования
    Queue<int> myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    std::cout << "Front: " << myQueue.front() << std::endl;  // Выводит "Front: 1"
    std::cout << "Size: " << myQueue.size() << std::endl;    // Выводит "Size: 3"

    myQueue.pop();

    std::cout << "Front: " << myQueue.front() << std::endl;  // Выводит "Front: 2"
    std::cout << "Size: " << myQueue.size() << std::endl;    // Выводит "Size: 2"

    return 0;
}
