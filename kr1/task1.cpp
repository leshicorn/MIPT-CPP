#include <iostream>
#include <cmath>

class Point
{
protected:
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) {}

    Point operator+(const Point& a) const
    {
        return Point(x + a.x, y + a.y);
    }

    Point operator-(const Point& a) const
    {
        return Point(x - a.x, y - a.y);
    }

    double dist() const
    {
        return sqrt(x * x + y * y);
    }
};

class Triangle
{
private:
    Point a;
    Point b;
    Point c;

public:
    Triangle(const Point& a, const Point& b, const Point& c) : a(a), b(b), c(c) {}

    double perimeter() const
    {
        double side1 = (a - b).dist();
        double side2 = (b - c).dist();
        double side3 = (c - a).dist();
        return side1 + side2 + side3;
    }
};

void base_test() {
    Point a(0, 0), b(0, 5), c(5, 0);
    Triangle t(a, b, c);
    std::cout << "Triangle perimeter: " << t.perimeter() << std::endl;
}

void normal_run() {
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Point a(x1, y1), b(x2, y2), c(x3, y3);
    Triangle t(a, b, c);
    std::cout << t.perimeter() << std::endl;
}

int main()
{
    base_test();
    normal_run();
    return 0;
}
