#include <iostream>
#include <string>

using namespace std;

string reverse(string line) {
    string reversed = "";
    for (auto it = line.rbegin(); it != line.rend(); ++it) {
        reversed += *it;
    }
    return reversed;
}

string dec_to_bin(int num) {
    string result = "";
    while (num != 0) {
        result += '0' + (num % 2);
        num /= 2;
    }
    return reverse(result);
}

int main() {
    int n = 0;
    cin >> n;
    cout << dec_to_bin(n) << endl;
}