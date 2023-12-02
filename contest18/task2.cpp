#include <cstddef>
#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
class Deque {
private:
    std::vector<T> head, tail;

public:
    bool Empty() const {
        return head.empty() && tail.empty();
    }

    size_t Size() const {
        return head.size() + tail.size();
    }

    void Clear() {
        head.clear();
        tail.clear();
    }

    const T& operator[](size_t i) const {
        return (i < head.size()) ? head[head.size() - 1 - i] : tail[i - head.size()];
    }

    T& operator[](size_t i) {
        return const_cast<T&>(static_cast<const Deque&>(*this)[i]);
    }

    const T& At(size_t i) const {
        if (i >= Size()) {
            throw std::out_of_range("Index out of range");
        }
        return (*this)[i];
    }

    T& At(size_t i) {
        return const_cast<T&>(static_cast<const Deque&>(*this).At(i));
    }

    const T& Front() const {
        if (head.empty()) {
            return tail.front();
        }
        return head.back();
    }

    T& Front() {
        return const_cast<T&>(static_cast<const Deque&>(*this).Front());
    }

    const T& Back() const {
        if (tail.empty()) {
            return head.front();
        }
        return tail.back();
    }

    T& Back() {
        return const_cast<T&>(static_cast<const Deque&>(*this).Back());
    }

    void PushFront(const T& elem) {
        head.push_back(elem);
    }

    void PushBack(const T& elem) {
        tail.push_back(elem);
    }
};

int main() {
    Deque<int> myDeque;

    // Добавление элементов в начало и конец
    myDeque.PushFront(1);
    myDeque.PushBack(2);
    myDeque.PushFront(3);
    myDeque.PushBack(4);

    // Вывод элементов через оператор []
    std::cout << "Elements using operator[]:" << std::endl;
    for (size_t i = 0; i < myDeque.Size(); ++i) {
        std::cout << myDeque[i] << " ";
    }
    std::cout << std::endl;

    // Вывод элементов через функцию At
    std::cout << "Elements using At():" << std::endl;
    for (size_t i = 0; i < myDeque.Size(); ++i) {
        std::cout << myDeque.At(i) << " ";
    }
    std::cout << std::endl;

    // Вывод первого и последнего элемента
    std::cout << "Front: " << myDeque.Front() << std::endl;
    std::cout << "Back: " << myDeque.Back() << std::endl;

    // Очистка дека
    myDeque.Clear();
    std::cout << "Deque cleared. Size: " << myDeque.Size() << std::endl;

    return 0;
}