/*
Этот код предоставляет реализацию класса Rational, представляющего рациональное число, и демонстрирует его использование в двух функциях: base_test() и normal_run().
Формат ввода и вывода:

    Формат ввода для normal_run():
        Пользователь вводит четыре целых числа a, b, c, и d, представляющих две рациональные дроби в формате "a/b" и "c/d".

    Формат вывода для normal_run():
        Выводятся результаты основных арифметических операций (+, -, *, /) между введенными рациональными числами, а также результаты умножения одного из них на целое число.

    Формат вывода для base_test():
        Выводятся результаты основных арифметических операций для двух заранее определенных рациональных чисел (a и b), а также результаты умножения каждого из них на целое число.

    Операции, поддерживаемые классом Rational:
        Сложение (+), вычитание (-), умножение (*), деление (/) двух рациональных чисел.
    
    input:
        1 2 1 3
    output:
        5/6
        1/6
        1/3
        3/2
        3/2
        4/3

        base_test():
        1/2
        1/3
        5/6
        1/6
        1/6
        3/2
        3/2
        4/3

*/

#include <iostream>

/**
 * @brief A class representing a rational number with basic arithmetic operations.
 */
class Rational {
public:
    /**
     * @brief Constructor for Rational class.
     * @param a Numerator of the rational number.
     * @param b Denominator of the rational number.
     */
    Rational(int a, int b) : numerator(a), denominator(b) {}

    /**
     * @brief Overloaded operator for addition of two rational numbers.
     * @param other The other rational number to be added.
     * @return The sum of two rational numbers.
     */
    Rational operator+(const Rational& other) const {
        int new_numerator = numerator * other.denominator + other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Rational(new_numerator, new_denominator);
    }

    /**
     * @brief Overloaded operator for subtraction of two rational numbers.
     * @param other The other rational number to be subtracted.
     * @return The difference of two rational numbers.
     */
    Rational operator-(const Rational& other) const {
        int new_numerator = numerator * other.denominator - other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Rational(new_numerator, new_denominator);
    }

    /**
     * @brief Overloaded operator for multiplication of two rational numbers.
     * @param other The other rational number to be multiplied.
     * @return The product of two rational numbers.
     */
    Rational operator*(const Rational& other) const {
        int new_numerator = numerator * other.numerator;
        int new_denominator = denominator * other.denominator;
        return Rational(new_numerator, new_denominator);
    }

    /**
     * @brief Overloaded operator for division of two rational numbers.
     * @param other The other rational number to be divided.
     * @return The quotient of two rational numbers.
     */
    Rational operator/(const Rational& other) const {
        int new_numerator = numerator * other.denominator;
        int new_denominator = denominator * other.numerator;
        return Rational(new_numerator, new_denominator);
    }

    /**
     * @brief Overloaded operator for multiplication of a rational number with an integer.
     * @param n The integer to be multiplied with the rational number.
     * @param r The rational number to be multiplied with the integer.
     * @return The product of the rational number and the integer.
     */
    friend Rational operator*(int n, const Rational& r) {
        return Rational(n * r.numerator, r.denominator);
    }

    /**
     * @brief Overloaded operator for multiplication of a rational number with an integer.
     * @param r The rational number to be multiplied with the integer.
     * @param n The integer to be multiplied with the rational number.
     * @return The product of the rational number and the integer.
     */
    friend Rational operator*(const Rational& r, int n) {
        return n * r;
    }

    /**
     * @brief Overloaded operator for outputting the rational number.
     * @param out The output stream.
     * @param r The rational number to be outputted.
     * @return The output stream.
     */
    friend std::ostream& operator<<(std::ostream& out, const Rational& r) {
        out << r.numerator << "/" << r.denominator;
        return out;
    }

private:
    int numerator; /**< Numerator of the rational number. */
    int denominator; /**< Denominator of the rational number. */
};

void base_test() {
    Rational a(1, 2);
    Rational b(1, 3);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << a + b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << a / b << std::endl;
    std::cout << 3 * a << std::endl;
    std::cout << b * 4 << std::endl;
}

void normal_run() {
    int a, b, c, d;
    std::cout << "Введите две рац.дроби в формате a b c d. Дроби будут иметь вид a/b, c/d\n";
    std::cin >> a >> b >> c >> d;
    Rational r1(a, b);
    Rational r2(c, d);
    std::cout << r1 + r2 << std::endl;
    std::cout << r1 - r2 << std::endl;
    std::cout << r1 * r2 << std::endl;
    std::cout << r1 / r2 << std::endl;
    std::cout << 3 * r1 << std::endl;
    std::cout << r2 * 4 << std::endl;
}

int main() {
    // base_test();
    normal_run();
    return 0;
}
