/*
Этот код реализует класс Polyline для представления ломаной линии в двумерном пространстве.
 Ломаная представляет собой последовательность точек, заданных координатами (x, y). Класс Polyline
  предоставляет функциональность для добавления точек, получения количества точек, получения длины ломаной
   и получения координат конкретной точки.

Формат ввода в функции normal_run:
    Сначала вводится количество точек (amo_dot).
    Затем вводятся координаты x и y для каждой из точек ломаной.
Формат вывода:
    Для каждой точки выводятся её координаты.
    После этого выводится длина ломаной.
Пример ввода/вывода:
    Input:
3
0.0 0.0
1.0 0.0
1.0 1.0

Output:
Length: 2.41421
Points:
0 0
1 0
1 1

*/

#include <iostream>
#include <vector>
#include <cmath>

class Polyline {
public:
    // Конструктор
    Polyline() {}

    // Добавить очередную точку в ломаную
    void addPoint(double x, double y) {
        points.push_back(std::make_pair(x, y));
    }

    // Получить количество точек в ломаной в данный момент
    unsigned int getNumberOfPoints() const {
        return points.size();
    }

    // Получить длину ломаной в данный момент
    double getLength() const {
        double length = 0.0;
        for (unsigned int i = 1; i < points.size(); i++) {
            double dx = points[i].first - points[i - 1].first;
            double dy = points[i].second - points[i - 1].second;
            length += std::sqrt(dx * dx + dy * dy);
        }
        return length;
    }

    // Получить x-координату i-ой точки ломаной
    double getX(unsigned int i) const {
        return points[i].first;
    }

    // Получить y-координату i-ой точки ломаной
    double getY(unsigned int i) const {
        return points[i].second;
    }

private:
    std::vector<std::pair<double, double>> points;
};

void base_test() {
    Polyline p;
    p.addPoint(0.0, 0.0);
    p.addPoint(1.0, 0.0);
    p.addPoint(1.0, 1.0);
    std::cout << "Length: " << p.getLength() << std::endl;
    std::cout << "Points:" << std::endl;
    for (unsigned int i = 0; i < p.getNumberOfPoints(); i++) {
        std::cout << p.getX(i) << " " << p.getY(i) << std::endl;
    }
    
}

void normal_run() {
    Polyline p;
    int amo_dot = 0;
    std::cin >> amo_dot;
    double x, y;
    for (int i = 0; i < amo_dot; i++) {
        std::cin >> x >> y;
        p.addPoint(x, y);
    }
    std::cout << "Length: " << p.getLength() << std::endl;
    std::cout << "Points:" << std::endl;
    for (unsigned int i = 0; i < p.getNumberOfPoints(); i++) {
        std::cout << p.getX(i) << " " << p.getY(i) << std::endl;
    }
}

int main() {
    base_test();
    normal_run();
    return 0;
}
