#include <iostream>

template <typename T>
class Vector2D {
public:
    // Конструкторы
    Vector2D();
    Vector2D(T x, T y);

    // Деструктор
    ~Vector2D();

    // Получение координат
    T getX() const;
    T getY() const;

    // Задание координат
    void setX(T x);
    void setY(T y);

    // Перегруженные операторы
    bool operator== (const Vector2D& v2) const;
    bool operator!= (const Vector2D& v2) const;
    Vector2D operator+ (const Vector2D& v2) const;
    Vector2D operator- (const Vector2D& v2) const;
    Vector2D operator* (const T a) const;

    // Оператор умножения скаляра на вектор
    friend Vector2D operator* (T a, const Vector2D& v) {
        return Vector2D(a * v.x, a * v.y);
    }

    // Вывод вектора, ожидается в формате (1; 1)
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        return os << "(" << v.x << "; " << v.y << ")";
    }

    // Чтение вектора, читает просто две координаты
    friend std::istream& operator>>(std::istream &is, Vector2D &v) {
        T x, y;
        is >> x >> y;
        v.x = x;
        v.y = y;
    return is;
}


private:
    T x;
    T y;
};

template <typename T>
Vector2D<T>::Vector2D() : x(T()), y(T()) {}

template <typename T>
Vector2D<T>::Vector2D(T x, T y) : x(x), y(y) {}

template <typename T>
Vector2D<T>::~Vector2D() {}

template <typename T>
T Vector2D<T>::getX() const {
    return x;
}

template <typename T>
T Vector2D<T>::getY() const {
    return y;
}

template <typename T>
void Vector2D<T>::setX(T x) {
    this->x = x;
}

template <typename T>
void Vector2D<T>::setY(T y) {
    this->y = y;
}

template <typename T>
bool Vector2D<T>::operator==(const Vector2D& v2) const {
    return x == v2.x && y == v2.y;
}

template <typename T>
bool Vector2D<T>::operator!=(const Vector2D& v2) const {
    return !(*this == v2);
}

template <typename T>
Vector2D<T> Vector2D<T>::operator+(const Vector2D& v2) const {
    return Vector2D(x + v2.x, y + v2.y);
}

template <typename T>
Vector2D<T> Vector2D<T>::operator-(const Vector2D& v2) const {
    return Vector2D(x - v2.x, y - v2.y);
}

template <typename T>
Vector2D<T> Vector2D<T>::operator*(const T a) const {
    return Vector2D(x * a, y * a);
}

int main() {
    Vector2D<int> v1;
    std::cout << "Enter a vector (int): ";
    std::cin >> v1;
    std::cout << "Read vector: " << v1 << std::endl;
    std::cout << "Vector multiplied by 42: " << v1 * 42 << std::endl;

    Vector2D<double> v2;
    std::cout << "Enter a vector (double): ";
    std::cin >> v2;
    std::cout << "Read vector: " << v2 << std::endl;
    std::cout << "Vector multiplied by 42: " << 42.0 * v2 << std::endl;

    return 0;
}
