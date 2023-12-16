#include <iostream>
#include <string>

using namespace std;
class Game {
public:
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

    void run_game() {
        string secretWord;
        int attempts;

        cin >> secretWord >> attempts;

        for (int i = 0; i < attempts; ++i) {
            string guess;
            cin >> guess;

            printResult(secretWord, guess);
        }
        return;
    }
};

int main() {

    Game game;
    game.run_game();    
    return 0;
}
