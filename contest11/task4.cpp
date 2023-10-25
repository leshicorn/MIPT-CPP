#include <iostream>
using namespace std;

// Шаблонный класс для размерной величины
template<int L, int M, int T>
class DimQ
{
public:
    double value;
    DimQ(double value) : value(value) {}
};

// Псевдонимы типов
typedef DimQ<1, 0, 0> Length;
typedef DimQ<0, 1, 0> Mass;
typedef DimQ<0, 0, 1> Time;
typedef DimQ<1, 0, -1> Velocity;
typedef DimQ<1, 0, -2> Acceleration; // Новый класс Acceleration

// Шаблонный оператор изменения знака
template<int L, int M, int T>
DimQ<L, M, T> operator-(const DimQ<L, M, T>& q)
{
    return DimQ<L, M, T>(-q.value);
}

// Шаблонный оператор сложения
template<int L, int M, int T>
DimQ<L, M, T> operator+(const DimQ<L, M, T>& q1, const DimQ<L, M, T>& q2)
{
    return DimQ<L, M, T>(q1.value + q2.value);
}

// Шаблонный оператор вычитания (новый)
template<int L, int M, int T>
DimQ<L, M, T> operator-(const DimQ<L, M, T>& q1, const DimQ<L, M, T>& q2)
{
    return DimQ<L, M, T>(q1.value - q2.value);
}

// Шаблонный оператор деления
template<int L1, int M1, int T1, int L2, int M2, int T2>
DimQ<L1 - L2, M1 - M2, T1 - T2> operator/(const DimQ<L1, M1, T1>& q1, const DimQ<L2, M2, T2>& q2)
{
    return DimQ<L1 - L2, M1 - M2, T1 - T2>(q1.value / q2.value);
}

// Шаблонный оператор умножения (новый)
template<int L1, int M1, int T1, int L2, int M2, int T2>
DimQ<L1 + L2, M1 + M2, T1 + T2> operator*(const DimQ<L1, M1, T1>& q1, const DimQ<L2, M2, T2>& q2)
{
    return DimQ<L1 + L2, M1 + M2, T1 + T2>(q1.value * q2.value);
}

// Шаблонный оператор вывода размерной величины
template<int L, int M, int T>
ostream& operator<<(ostream& os, const DimQ<L, M, T>& q)
{
    os << q.value << " ";
    if (L != 0)
        os << "m^(" << L << ")";
    if (M != 0)
        os << "kg^(" << M << ")";
    if (T != 0)
        os << "s^(" << T << ")";
    return os;
}

// Специализированный оператор вывода для Velocity
ostream& operator<<(ostream& os, const Velocity& v)
{
    os << v.value << " m/s";
    return os;
}

// Специализированный оператор вывода для Acceleration
ostream& operator<<(ostream& os, const Acceleration& a)
{
    os << a.value << " m/s^2";
    return os;
}

int main()
{
    // Длина
    Length l1 = {100};
    Length l2 = {200};
    // Время
    Time t = {20};
    // Скорость
    Velocity v = (l2 - l1) / t;
    // Ускорение
    Acceleration a = v / t;
    // Выводим величины
    cout << v << endl;
    cout << a << endl;
    cout << (l1 + l2) * v / (t * a) << endl;
    return 0;
}
