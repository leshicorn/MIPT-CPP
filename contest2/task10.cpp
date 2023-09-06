#include <iostream>
#include <string>

using namespace std;

char unleveling(char c) {
	if (c >= 'a' && c <= 'z')
		c += 'A' - 'a';
	return c;
}

char get_a_letter() {
    char c;
    while (true) {
        cin >> c;
        if (isalpha(c)) {
            return toupper(c);
        }
    }
}

int main() {
	for (int i = 0; i < 10; i++) {
		cout << unleveling(get_a_letter());
    }
	cout << endl;
	return 0;
}