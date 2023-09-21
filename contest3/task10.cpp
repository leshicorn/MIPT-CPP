#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int abss(int x) {
    return x < 0 ? -x : x;
}

bool compare(int a, int b) {
    if (abss(a) < abss(b)) 
        return true;
    return false;
}

int main() {
    int n = 0;
    cin >> n;

    vector<int> less;
    vector<int> more;

    for (int i = 0; i < n; i++) {
        int inp = 0;
        cin >> inp;
        if (inp > 0) {
            more.push_back(inp);
        }
        else {
            less.push_back(inp);
        }
    }
    sort(more.begin(), more.end());
    sort(less.begin(), less.end(), compare);

    for (int i = 0; i < more.size(); i++) {
        cout << more[i] << " ";
    }

    for (int i = 0; i < less.size(); i++) {
        cout << less[i] << " ";
    }
    cout << "\n";

}