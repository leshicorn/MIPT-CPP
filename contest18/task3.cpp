#include <iostream>
#include <vector>

template <typename T>
class MathVector {
private:
    std::vector<T> data;

public:
    MathVector(size_t n) : data(n, T()) {}

    MathVector(std::initializer_list<T> init) : data(init) {}

    template <typename Iter>
    MathVector(Iter first, Iter last) : data(first, last) {}

    size_t Dimension() const {
        return data.size();
    }

    T& operator[](size_t i) {
        return data[i];
    }

    const T& operator[](size_t i) const {
        return data[i];
    }

    MathVector<T>& operator+=(const MathVector<T>& other) {
        if (Dimension() != other.Dimension()) {
            throw std::invalid_argument("Vectors must have the same dimension");
        }

        for (size_t i = 0; i < Dimension(); ++i) {
            data[i] += other[i];
        }

        return *this;
    }

    friend MathVector<T> operator+(MathVector<T> lhs, const MathVector<T>& rhs) {
        return lhs += rhs;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const MathVector<T>& v) {
    out << '(';
    for (size_t i = 0; i != v.Dimension(); ++i) {
        if (i > 0) {
            out << ", ";
        }
        out << v[i];
    }
    out << ')';
    return out;
}

template <typename T>
MathVector<T>& operator*=(MathVector<T>& v, const T& scalar) {
    for (size_t i = 0; i != v.Dimension(); ++i) {
        v[i] *= scalar;
    }
    return v;
}

template <typename T>
MathVector<T> operator*(const MathVector<T>& v, const T& scalar) {
    auto tmp(v);
    tmp *= scalar;
    return tmp;
}

template <typename T>
MathVector<T> operator*(const T& scalar, const MathVector<T>& v) {
    return v * scalar;
}

int main() {
    MathVector<int> v1{1, 2, 3};
    MathVector<int> v2{4, 5, 6};

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;

    MathVector<int> sum = v1 + v2;
    std::cout << "v1 + v2: " << sum << std::endl;

    v1 += v2;
    std::cout << "v1 += v2: " << v1 << std::endl;

    return 0;
}
