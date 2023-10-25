#include <iostream>
#include <algorithm>
#include <vector>

void print_reverse(int* arr, int n) {
    for (int i = n - 1; i >= 0; i--) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int n = 0;
    std::cin >> n;
    int* arr = new int[n];
    
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    print_reverse(arr, n);

    return 0;
}