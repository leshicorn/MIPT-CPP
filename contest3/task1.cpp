#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int* arr = new int[n];
    long long int sum = 0;
    int amo = 0;
    double mid = 0.0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        amo++;
    }

    if (n == 1) {
        cout << arr[0] << endl;
        return 0;
    }

    mid = static_cast<double>(sum) / static_cast<double>(amo);

    for (int i = 0; i < n; i++) {
        if (static_cast<double>(arr[i]) > mid) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}