#include <vector>
#include <iostream>

template <typename T>
class Table {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    // Конструктор с начальными размерами таблицы
    Table(size_t initialRows, size_t initialCols) : rows(initialRows), cols(initialCols) {
        data.resize(rows, std::vector<T>(cols));
    }

    // Константная версия оператора []
    const std::vector<T>& operator[](size_t index) const {
        return data[index];
    }

    // Неконстантная версия оператора []
    std::vector<T>& operator[](size_t index) {
        return data[index];
    }

    // Функция изменения размера таблицы
    void resize(size_t newRows, size_t newCols) {
        data.resize(newRows, std::vector<T>(newCols, T()));
        rows = newRows;
        cols = newCols;
    }

    // Функция получения размера таблицы
    std::pair<size_t, size_t> size() const {
        return std::make_pair(rows, cols);
    }
};

int main() {
    // Пример использования
    Table<int> myTable(3, 4);

    // Заполнение таблицы значениями
    for (size_t i = 0; i < myTable.size().first; ++i) {
        for (size_t j = 0; j < myTable.size().second; ++j) {
            myTable[i][j] = i * myTable.size().second + j;
        }
    }

    // Вывод значений таблицы
    for (size_t i = 0; i < myTable.size().first; ++i) {
        for (size_t j = 0; j < myTable.size().second; ++j) {
            std::cout << myTable[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Изменение размера таблицы
    myTable.resize(2, 3);

    // Вывод новых значений таблицы
    for (size_t i = 0; i < myTable.size().first; ++i) {
        for (size_t j = 0; j < myTable.size().second; ++j) {
            std::cout << myTable[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
