#include <iostream>
#include <string>

using namespace std;

int main() {
    int a = 0;

    cin >> a;

    string line = (a % 13 == 0) ? "Yes" : "No";

    cout << line << endl; 
}