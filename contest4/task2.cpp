#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::pair<int, int> > array;

    int q = 0;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        std::string input = "";
        std::cin >> input;

        if (input == "WORRY") {
            int i = 0;
            std::cin >> i;
            array[i].second = 1;
        }
        else if (input == "QUIET") {
            int i = 0;
            std::cin >> i;
            array[i].second = 0;
        }
        else if (input == "COME") {
            int k = 0;
            std::cin >> k;
            if (k > 0) {
                int start_ind;
                if (array.size() > 0)
                    start_ind = array[array.size() - 1].first;
                else
                    start_ind = 0;
                for (int i = 0; i < k; i++) {
                    array.push_back({start_ind + i + 1, 0});
                }
            }
            else 
            {
                for (int i = 0; i < -k; i++) {
                    array.pop_back();
                }
            }
        }
        else if (input == "WORRY_COUNT") {
            int amo = 0;
            for (int j = 0; j < array.size(); j++) {
                amo += array[j].second;
            }
            std::cout << amo << "\n";
        }
    }

}