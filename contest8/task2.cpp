#include <iostream>
#include <algorithm>
#include <vector>

class Storage {
private:
    int* data; // Указатель на массив int
    unsigned int size; // Размер хранилища

public:
    // Конструктор хранилища размерности n
    Storage(unsigned int n) {
        size = n;
        data = new int[size];
    }

    // Виртуальный деструктор
    virtual ~Storage() {
        delete[] data;
    }

    // Деструктор для освобождения выделенной памяти
    // ~Storage() {
    //     delete[] data;
    // }

    // Получение размерности хранилища
    unsigned getSize() {
        return size;
    }

    // Получение значения i-го элемента из хранилища
    int getValue(unsigned int i) {
        return data[i];
    }

    // Задание значения i-го элемента из хранилища равным value
    void setValue(unsigned int i, int value) {
        data[i] = value;
    }
};

class TestStorage : public Storage {
private:
    int* more_data;

public:
    // Конструктор хранилища размерности n
    TestStorage(unsigned int n) : Storage(n) {
        more_data = new int[n];
    }

    // Деструктор для освобождения выделенной памяти
    ~TestStorage() {
        delete[] more_data;
    }
};


int main() {
    Storage* ts = new TestStorage(42);
    delete ts;

    return 0;
}
