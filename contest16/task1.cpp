#include <iostream>
#include <stdexcept>

class IncorrectIndexException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Incorrect index exception";
    }
};

class Storage {
private:
    int* data;
    unsigned int size;

public:
    Storage(unsigned int n) : size(n) {
        if (n == 0) {
            throw std::invalid_argument("Storage size should be greater than 0");
        }
        data = new int[n];
    }

    ~Storage() {
        delete[] data;
    }

    unsigned int getSize() const {
        return size;
    }

    int getValue(unsigned int i) const {
        if (i >= size) {
            throw IncorrectIndexException();
        }
        return data[i];
    }

    void setValue(unsigned int i, int value) {
        if (i >= size) {
            throw IncorrectIndexException();
        }
        data[i] = value;
    }
};

int main() {
    try {
        unsigned int index;
        std::cout << "Enter an index: ";
        std::cin >> index;

        Storage s(42);
        s.setValue(index, 0);
        std::cout << "Value at index " << index << ": " << s.getValue(index) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
