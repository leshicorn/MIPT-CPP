#include <iostream>
#include <cmath>

class Coord {
public:
    int x;
    int y;
};

// Класс треугольник
class Triangle {
public:
    Coord p1, p2, p3;
};

// Функция для получения координат точки
Coord getPoint() {
    Coord point;
    std::cin >> point.x >> point.y;
    return point;
}

// Функция для получения данных треугольника
void getTri(Triangle& tri) {
    tri.p1 = getPoint();
    tri.p2 = getPoint();
    tri.p3 = getPoint();
}

// Вспомогательная функция для сравнения треугольников
int cmp(Triangle a, Triangle b) {
    auto rotate = [](Coord& point, double angle) {
        double x = point.x;
        double y = point.y;
        point.x = round(x * cos(angle) - y * sin(angle));
        point.y = round(x * sin(angle) + y * cos(angle));
    };

    auto translate = [](Triangle& tri, int dx, int dy) {
        tri.p1.x += dx;
        tri.p1.y += dy;
        tri.p2.x += dx;
        tri.p2.y += dy;
        tri.p3.x += dx;
        tri.p3.y += dy;
    };

    // Попытка найти совпадение после всех возможных поворотов и переносов
    for (int i = 0; i < 360; i += 90) {
        for (int j = 0; j < 2; j++) {
            if (a.p1.x == b.p1.x && a.p1.y == b.p1.y &&
                a.p2.x == b.p2.x && a.p2.y == b.p2.y &&
                a.p3.x == b.p3.x && a.p3.y == b.p3.y) {
                return 1; // Треугольники равны
            }
            rotate(a.p1, M_PI / 90 * i);
            rotate(a.p2, M_PI / 90 * i);
            rotate(a.p3, M_PI / 90 * i);
        }
        translate(a, 0, 1);
    }

    return 0; // Треугольники не равны
}

int main() {
    // Ввод данных для первого треугольника
    Triangle triA;
    getTri(triA);

    // Ввод данных для второго треугольника
    Triangle triB;
    getTri(triB);

    // Сравнение треугольников и вывод результата
    std::cout << cmp(triA, triB) << std::endl;

    return 0;
}
