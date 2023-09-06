#include <iostream>

using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    int** table = new int*[n];
    int** transp = new int*[m];

    for (int i = 0; i < n; i++) {
        table[i] = new int[m];
    }

    for (int i = 0; i < m; i++) {
        transp[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transp[j][i] = table[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << transp[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] table[i];
    }

    for (int i = 0; i < m; i++) {
        delete[] transp[i];
    }

    delete[] table;
    delete[] transp;
}