#include <iostream>
#include <algorithm>
#include <limits.h>

int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> arr[i][j];
        }
    }

    int sum = 0;
    int max = INT_MIN;
    int ind = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum += arr[j][i];
        }
        if (sum > max) {
            max = sum;
            ind = i;
        }
        sum = 0;
    }

    std :: cout << ind << "\n";

}