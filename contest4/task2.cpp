#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> v;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        int inp = 0;
        cin >> inp;
        v.push_back(inp);
        sum += inp;
    }

    double mid = static_cast<double>(sum) / static_cast<double>(n);
    vector<int> days;
    for (int i = 0; i < n; i++) {
        if (static_cast<double>(v[i]) > mid) {
            days.push_back(i);
        }
    }

    cout << days.size() << endl;
    for (int i = 0; i < days.size(); i++) {
        cout << days[i] << " ";
    }
    cout << endl;
}