#include <iostream>

class Vector2D
{
public:
    // Конструкторы
    Vector2D() : x(0), y(0) {}
    Vector2D(int x, int y) : x(x), y(y) {}

    // Деструктор
    ~Vector2D() {}

    // Получение координат
    int getX() const { return x; }
    int getY() const { return y; }

    // Задание координат
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    // Перегруженный оператор - сравнение двух векторов на равенство
    bool operator== (const Vector2D& v2) const
    {
        return (x == v2.x) && (y == v2.y);
    }

    // Ещё один перегруженный оператор - неравенство векторов
    bool operator!= (const Vector2D& v2) const
    {
        return !(*this == v2);
    }

    // Сумма двух векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator+ (const Vector2D& v2) const
    {
        return Vector2D(x + v2.x, y + v2.y);
    }

    // Вычитание векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator- (const Vector2D& v2) const
    {
        return Vector2D(x - v2.x, y - v2.y);
    }

    // Оператор умножения вектора на скаляр, исходный вектор не меняется, возвращается новый вектор
    Vector2D operator* (const int a) const
    {
        return Vector2D(x * a, y * a);
    }
private:
    int x;
    int y;
};

// Оператор умножения скаляра на вектор (снаружи класса)
Vector2D operator* (int a, const Vector2D& v)
{
    return Vector2D(v.getX() * a, v.getY() * a);
}

// Вывод вектора
std::ostream& operator<<(std::ostream& os, const Vector2D& v)
{
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
}

// Чтение вектора
std::istream& operator>>(std::istream& is, Vector2D& v)
{
    int x, y;
    is >> x >> y;
    v.setX(x);
    v.setY(y);
    return is;
}

int main()
{
    Vector2D v1;
    std::cin >> v1;
    std::cout << v1 << std::endl;
    Vector2D v2;
    std::cin >> v2;
    std::cout << v2 << std::endl;
    std::cout << std::boolalpha << (v1 == v2) << std::endl;
    std::cout << std::boolalpha << (v1 != v2) << std::endl;
    Vector2D v3 = v1 - v2;
    std::cout << v3 << std::endl;
    std::cout << v3 * 42 << std::endl;
    std::cout << 42 * v3 << std::endl;

    return 0;
}
