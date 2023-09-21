#include <iostream>

using namespace std;
struct Vector {
    int x, y, z;
};

Vector sum(Vector a, Vector b) {
    // Vector res = {0, 0, 0};
    // res.x = a.x + b.x;
    // res.y = a.y + b.y;
    // res.z = a.z + b.z;

    return {a.x + b.x, a.y + b.y, a.z + b.z};
}


const int N = 3;

int main() {
    Vector res = {
        0,
        0,
        0
    };
    for (int i = 0; i < N; i++) {
        Vector tmp;
        cin >> tmp.x >> tmp.y >> tmp.z;
        res = sum(res, tmp);
    }
    cout << res.x << " " << res.y << " " << res.z << endl;
    return 0;
}