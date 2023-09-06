#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int** table = new int*[n];
    for (int i = 0; i < n; i++) {
        table[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> table[i][j];
        }
    }

    int** table_transp = new int*[n];
    for (int i = 0; i < n; i++) {
        table_transp[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            table_transp[i][j] = table[j][i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << table_transp[i][j] << " ";
        }
        cout << endl;
    }
    
}