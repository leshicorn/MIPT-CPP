#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string dec_to_bin(int num) {
    string result = "";
    while (num != 0) {
        result += '0' + (num % 2);
        num /= 2;
    }
    return result;
}

int main() {
    int n = 0;
    cin >> n;
    string result = dec_to_bin(n);
    sort(result.begin(), result.end(), greater());
    cout << result << endl;
}