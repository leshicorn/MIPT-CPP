#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int inp = 0;
        cin >> inp;
        arr.push_back(inp);
    }

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    int m = 0;
    cin >> m;

    vector<int> res;

    for (int i = 0; i < m; i++) {
        res.push_back(arr[i]);
    }
    reverse(res.begin(), res.end());

    for (int i = 0; i < m; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}