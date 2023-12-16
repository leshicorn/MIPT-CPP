#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

int main() {
    int x0, y0, z0, r;
    cin >> x0 >> y0 >> z0 >> r;
    int n = 0;
    cin >> n;
    vector<pair<int, int>> res(n + 1);
    int amo = 0;

    unordered_set<int> uniq_id;

    for (int i = 0; i < n; i++) {
        unsigned long long uuid, ts;
        double x, y, z;
        cin >> uuid >> ts >> x >> y >> z;

        double distance = sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0) + (z - z0) * (z - z0));
        if (distance < r) {
            if (uniq_id.insert(uuid).second) {
                res[amo].first = ts;
                res[amo].second = uuid;
                amo++;
            }
        }
    }

    sort(res.begin(), res.begin() + amo);

    short out = 0;
    for (int i = 0; i < amo; i++) {
        cout << res[i].second << '\n';
        out++;
    }
    if (out == 0) {
        cout << "None\n";
    }
}
