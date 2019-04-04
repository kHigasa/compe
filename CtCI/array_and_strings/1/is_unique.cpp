#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isUnique(const string &str) {
    vector<bool> char_vec(128, false);
    for (int i = 0; i < str.length(); ++i) {
        if (char_vec[str[i]]) return false;
        else char_vec[str[i]] = true;
    }

    return true;
}

int main() {
    vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
    for (auto word : words) {
        string ans = isUnique(word) ? "is unique." : "is not unique.";
        cout << word << " " << ans << endl;
    }

    return 0;
}

