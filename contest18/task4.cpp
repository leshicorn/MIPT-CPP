#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

template <typename T>
class Polynomial {
private:
    std::vector<T> coefficients;

public:
    // Constructors
    Polynomial() : coefficients{0} {}
    
    explicit Polynomial(const T& coef) : coefficients{coef} {}
    
    Polynomial(std::initializer_list<T> init) : coefficients(init) {}
    
    template <typename Iter>
    Polynomial(Iter first, Iter last) : coefficients{first, last} {}
    
    // Comparison operators
    bool operator==(const Polynomial<T>& other) const {
        return coefficients == other.coefficients;
    }

    bool operator!=(const Polynomial<T>& other) const {
        return coefficients != other.coefficients;
    }

    // Arithmetic operators
    Polynomial<T> operator+(const Polynomial<T>& other) const {
        Polynomial<T> result(*this);
        result += other;
        return result;
    }

    Polynomial<T> operator-(const Polynomial<T>& other) const {
        Polynomial<T> result(*this);
        result -= other;
        return result;
    }

    Polynomial<T> operator*(const Polynomial<T>& other) const {
        Polynomial<T> result;
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return result;
    }

    // Compound assignment operators
    Polynomial<T>& operator+=(const Polynomial<T>& other) {
        coefficients.resize(std::max(coefficients.size(), other.coefficients.size()), T());
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            coefficients[i] += other.coefficients[i];
        }
        return *this;
    }

    Polynomial<T>& operator-=(const Polynomial<T>& other) {
        coefficients.resize(std::max(coefficients.size(), other.coefficients.size()), T());
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            coefficients[i] -= other.coefficients[i];
        }
        return *this;
    }

    Polynomial<T>& operator*=(const Polynomial<T>& other) {
        *this = *this * other;
        return *this;
    }

    // Access operators
    const T& operator[](size_t degree) const {
        return (degree < coefficients.size()) ? coefficients[degree] : T();
    }

    // Degree method
    size_t Degree() const {
        return (coefficients.empty()) ? -1 : coefficients.size() - 1;
    }

    // Evaluation operator
    T operator()(const T& value) const {
        T result = 0;
        T power = 1;
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result += coefficients[i] * power;
            power *= value;
        }
        return result;
    }

    // Output operator
    friend std::ostream& operator<<(std::ostream& out, const Polynomial<T>& poly) {
        for (int i = poly.Degree(); i >= 0; --i) {
            out << poly[i] << " ";
        }
        return out;
    }

    // Iterator methods
    auto begin() const {
        return std::find_if(coefficients.rbegin(), coefficients.rend(), [](const T& coef) {
            return coef != T();
        }).base();
    }

    auto end() const {
        return coefficients.end();
    }
};

int main() {
    Polynomial<int> p1({1, 2, 3});  // 3x^2 + 2x + 1
    Polynomial<int> p2({4, 5, 6});  // 6x^2 + 5x + 4

    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;

    Polynomial<int> sum = p1 + p2;
    std::cout << "p1 + p2: " << sum << std::endl;

    p1 += p2;
    std::cout << "p1 += p2: " << p1 << std::endl;

    std::cout << "Degree of p1: " << p1.Degree() << std::endl;
    std::cout << "p1(2): " << p1(2) << std::endl;

    return 0;
}
