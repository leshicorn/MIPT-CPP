#include <iostream>
#include <cmath>

class Point {
protected:
    double _x;
    double _y;
    double _z;

public:
    Point(double x, double y, double z) : _x(x), _y(y), _z(z) {}

    double x() const {
        return _x;
    }

    double y() const {
        return _y;
    }

    double z() const {
        return _z;
    }
};

class Sphere {
public:
    // Конструктор сферы с центром в точке center и радиусом r
    Sphere(const Point& center, double r) : _center(center), _radius(r) {
        std::cout << "Creating sphere with center (" << center.x() << "; " << center.y() << "; " << center.z() << ") and R = " << r << std::endl;
    }

    // Проверка, попадает ли заданная точка p в данную сферу.
    // (Расстояния сравнивать с точностью 1e-6.)
    bool covers(const Point& p) const {
        double distance = std::sqrt(std::pow(p.x() - _center.x(), 2) +
                                    std::pow(p.y() - _center.y(), 2) +
                                    std::pow(p.z() - _center.z(), 2));
        return distance <= _radius + 1e-6;
    }

private:
    Point _center;
    double _radius;
};

int main() {
    double center_x, center_y, center_z, radius;
    std::cin >> center_x >> center_y >> center_z >> radius;

    Point center(center_x, center_y, center_z);
    Sphere sphere(center, radius);

    int numPoints;
    std::cin >> numPoints;

    for (int i = 0; i < numPoints; ++i) {
        double px, py, pz;
        std::cin >> px >> py >> pz;
        Point point(px, py, pz);

        std::cout << "Testing point (" << px << "; " << py << "; " << pz << "). The point is inside sphere: " << std::boolalpha << sphere.covers(point) << std::endl;
    }

    return 0;
}
