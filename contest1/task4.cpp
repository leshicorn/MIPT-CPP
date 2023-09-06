#include <iostream>

using namespace std;

int absolute(int x) {
    if (x < 0)
        return -x;
    return x;
}

int main() {
    int n = 0;
    cin >> n;
    int temp;
    int max_abs = -1;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (absolute(temp) > absolute(max_abs))
            max_abs = temp;
    }

    cout << max_abs << endl;
}