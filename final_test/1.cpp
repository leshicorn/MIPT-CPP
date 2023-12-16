#include <iostream>
#include <string>

using namespace std;

void printResult(const string& secretWord, const string& guess) {
    for (size_t i = 0; i < secretWord.length(); ++i) {
        if (secretWord[i] == guess[i]) {
            cout << 'g';
        } else if (secretWord.find(guess[i]) != string::npos) {
            cout << 'y';
        } else {
            cout << '-';
        }
    }
    cout << endl;
}

int main() {
    string secretWord;
    int attempts;

    cin >> secretWord >> attempts;

    for (int i = 0; i < attempts; ++i) {
        string guess;
        cin >> guess;

        printResult(secretWord, guess);
    }

    return 0;
}
