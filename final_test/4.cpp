#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

class Point {
public:
    int x;
    int y;
    int brightness;
};

bool operator<(const Point& lhs, const Point& rhs) {
    if (lhs.x == rhs.x) {
        if (lhs.y == rhs.y) {
            return lhs.brightness > rhs.brightness;
        } else {
            return lhs.y > rhs.y;
        }
    } else {
        return lhs.x > rhs.x;
    }
}

bool shouldIncludePoint(const Point& point) {
    return (point.brightness >= 10) || (pow(point.x, 2) + pow(point.y, 2) <= 10000);
}

bool sortByBrightness(const pair<Point, int>& a, const pair<Point, int>& b) {
    if (a.first.brightness == b.first.brightness) {
        if (a.second == b.second) {
            return pow(a.first.x, 2) + pow(a.first.y, 2) < pow(b.first.x, 2) + pow(b.first.y, 2);
        } else {
            return a.second > b.second;
        }
    } else {
        return a.first.brightness > b.first.brightness;
    }
}

int main() {
    int N = 0;
    cin >> N;

    map<Point, int> points;
    for (int i = 0; i < N; ++i) {
        int x = 0, y = 0, brightness = 0;
        cin >> x >> y >> brightness;
        points[{x, y, brightness}]++;
    }

    vector<pair<Point, int>> pairs;
    for (auto& entry : points) {
        if (entry.second >= 2 || shouldIncludePoint(entry.first)) {
            pairs.push_back(entry);
        }
    }

    sort(pairs.begin(), pairs.end(), sortByBrightness);

    for (auto& [key, value] : pairs) {
        cout << key.x << ' ' << key.y << ' ' << key.brightness << endl;
    }
}