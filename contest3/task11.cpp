#include <iostream>
#include <algorithm>

using namespace std;

typedef struct candy {
    int price, amount;
} candy;

bool compare(const candy& c1, const candy& c2) {
    return c1.price < c2.price;
}

int main() {
    int n = 0;
    cin >> n;
    candy* arr = new candy[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].price >> arr[i].amount;
    }
    
    int sum = 0;
    cin >> sum;

    sort(arr, arr + n, compare);

    int amount = 0;
    int candy_amount = 0;

    for (int i = 0; i < n; i++) {
        if (sum >= arr[i].price) {
            sum -= arr[i].price;
            amount++;
            candy_amount += arr[i].amount;
        }
    }

    cout << amount << " " << candy_amount << "\n";

    delete[] arr;
}