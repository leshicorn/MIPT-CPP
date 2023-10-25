#include <iostream>
#include <algorithm>
#include <vector>

bool check_equal(std::vector<int> &a, std::vector<int> &b, int n) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> seq1(n);
    std::vector<int> seq2(n);

    for (int i = 0; i < n; i++) {
        std::cin >> seq1[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> seq2[i];
    }
    
    bool res = check_equal(seq1, seq2, n);
    if (res)
        std::cout << "true\n";
    else
        std::cout << "false\n";

    return 0;
}