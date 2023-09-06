#include <iostream>
#include <algorithm>
#include <vector>
#include <istream>

using namespace std;

int main() {
    int n = 0, m = 0;
     scanf("%d%d", &n, &m);

    getc(stdin);
    char** table = new char*[n];
    char** rotated = new char*[m];

    for (int i = 0; i < n; i++) {
        table[i] = new char[m];
    }

    for (int i = 0; i < m; i++) {
        rotated[i] = new char[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            table[i][j] = getc(stdin);
        }
        getc(stdin);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            rotated[i][j] = table[j][m - 1 - i];
        }
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", rotated[i][j]);
        }
        printf("\n");
    }

}