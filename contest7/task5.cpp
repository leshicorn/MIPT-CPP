#include <iostream>
#include <vector>
#include <utility>
#include <string>

class MyClass {
private:
    std::vector<std::pair<int, std::string>> elements;

public:
    // Метод для добавления новой структуры в массив
    void addElement(int num, const std::string& str) {
        // Проверяем, нет ли уже такой структуры в векторе
        for (const auto& element : elements) {
            if (element.first == num && element.second == str) {
                return; // Структура уже существует, ничего не добавляем
            }
        }

        // Если структура не найдена, добавляем её в вектор
        elements.push_back(std::make_pair(num, str));
    }

    // Метод для распечатки содержимого элементов массива
    void printStructures() const {
        for (const auto& element : elements) {
            std::cout << element.first << " " << element.second << std::endl;
        }
    }

    // Перегрузка оператора +=
    MyClass& operator+=(const MyClass& other) {
        for (const auto& element : other.elements) {
            bool found = false;
            for (const auto& existingElement : elements) {
                if (element.first == existingElement.first && element.second == existingElement.second) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                elements.push_back(element);
            }
        }
        return *this;
    }
};

int main() {
    MyClass obj1;
    obj1.addElement(1, "hi");
    obj1.addElement(2, "hello");
    obj1.addElement(2, "hello");

    MyClass obj2;
    obj2.addElement(3, "hey");
    obj2.addElement(4, "pop");
    obj2.addElement(2, "hello");
    obj2.addElement(5, "hello");

    obj1 += obj2;

    obj1.printStructures();

    return 0;
}
