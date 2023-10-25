#include <iostream>
#include <vector>

class VectorN
{
public:
    // Конструктор вектора размерности n
    VectorN(unsigned int n) : size(n), values(n, 0) {}

    // Деструктор
    ~VectorN() {}

    // Получение размерности вектора
    unsigned getSize() const
    {
        return size;
    }

    // Получение значения i-ой координаты вектора,
    // i находится в диапазоне от 0 до n-1
    int getValue(unsigned int i) const
    {
        if (i < size)
            return values[i];
        return 0; // Возвращаем 0 в случае неверного индекса
    }

    // Задание значения i-ой координаты вектора равным value,
    // i находится в диапазоне от 0 до n-1
    void setValue(unsigned int i, int value)
    {
        if (i < size)
            values[i] = value;
    }

    // Оператор == проверяет два вектора на равенство
    bool operator== (const VectorN& v2) const
    {
        if (size != v2.size)
            return false;

        for (unsigned int i = 0; i < size; ++i)
        {
            if (values[i] != v2.values[i])
                return false;
        }

        return true;
    }

    // Оператор != проверяет два вектора на неравенство
    bool operator!= (const VectorN& v2) const
    {
        return !(*this == v2);
    }

    // Оператор + складывает два вектора покоординатно
    VectorN operator+ (const VectorN& v2) const
    {
        if (size != v2.size)
            return *this; // Возвращаем текущий вектор, если размерности разные

        VectorN result(size);
        for (unsigned int i = 0; i < size; ++i)
        {
            result.values[i] = values[i] + v2.values[i];
        }
        return result;
    }

    // Оператор * умножает вектор на скаляр типа int покоординатно
    VectorN operator* (const int a) const
    {
        VectorN result(size);
        for (unsigned int i = 0; i < size; ++i)
        {
            result.values[i] = values[i] * a;
        }
        return result;
    }

    // Оператор * умножает скаляр на вектор (снаружи класса)
    friend VectorN operator* (const int a, const VectorN& v)
    {
        return v * a;
    }

private:
    unsigned int size;
    std::vector<int> values;
};

int main()
{
    VectorN a(4);
    a.setValue(0, 0);
    a.setValue(1, 1);
    a.setValue(2, 2);
    a.setValue(3, 3);

    VectorN b(4);
    b.setValue(0, 0);
    b.setValue(1, -1);
    b.setValue(2, -2);
    b.setValue(3, -3);

    std::cout << (a == b) << std::endl;
    std::cout << (a != b) << std::endl;

    VectorN c = a + b;
    VectorN d = 5 * c;

    for (unsigned int i = 0; i < a.getSize(); ++i)
        std::cout << d.getValue(i) << std::endl;

    return 0;
}
