#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <forward_list>
#include <string.h>
#include <ctype.h>

using namespace std;

/**
 * @brief checks if strings are equal if we don't care about registers
 * 
 * @param s1 
 * @param s2 
 * @return true 
 * @return false 
 */
bool is_equal(string s1, string s2) {
    string s1_c = s1, s2_c = s2;
    transform(s1_c.begin(), s1_c.end(), s1_c.begin(), ::tolower);
    transform(s2_c.begin(), s2_c.end(), s2_c.begin(), ::tolower);

    return (s1_c == s2_c);
}

bool is_absolute_equal(string s1, string s2) {
    return (s1 == s2);
}
int calculate_amount_of_unique_strings(vector<string> arr) {
    vector<string> uniqueStrings;
    for (size_t i = 0; i < arr.size(); ++i) {
        bool found = false;
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            if (is_absolute_equal(arr[i], *it)) {
                found = true;
                break;
                }
        }
        if (!found) {
            uniqueStrings.push_back(arr[i]);
        }
    }
    return uniqueStrings.size();
}

int main() {
    int n = 0;
    cin >> n;
    vector<string> arr (n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        string same_str = "";
        vector <string> string_check;
        for (int j = 0; j < n; j++) {
            // check if they are the same and not pointing to themselves
            if (is_equal(arr[i], arr[j]) && i != j) {
                string_check.push_back(arr[j]);
                same_str = arr[j];
            }
        }
        int res = calculate_amount_of_unique_strings(string_check);
        if (res > 2) {
            cout << same_str << "\n";
        }
    }

}