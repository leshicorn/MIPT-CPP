#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <forward_list>

using namespace std;

class Point {
protected:
    double _x;
    double _y;
    double _z;
public:
    Point(double x, double y, double z): _x(x), _y(y), _z(z) {}

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

class Scene
{
private:
    vector<Point> points;

public:
    virtual bool contains(const Point& p) const;
    void append(const Point& p);
    unsigned long size() const;

    // Operator overloads for accessing points by index
    const Point& operator[](unsigned int index) const {
        return points[index];
    }
};

bool Scene::contains(const Point& p) const {
    // Implementation for contains method goes here
    return true; // Modify this according to your logic
}

void Scene::append(const Point& p) {
    if (contains(p)) {
        points.push_back(p);
    }
}

unsigned long Scene::size() const {
    return points.size();
}

int main() {
    Scene s;

    Point p1(10.1, 10.1, 10.1);
    Point p2(2, 2, 2);

    s.append(p1);
    s.append(p2);

    for(unsigned int i = 0; i < s.size(); i++) {
        const Point& p = s[i];
        cout << p.x() << " " << p.y() << " " << p.z() << endl;
    }

    return 0;
}
