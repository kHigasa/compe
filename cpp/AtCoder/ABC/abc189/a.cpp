#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    if (s[0]==s[1] && s[0]==s[2]) {
        cout << "Won" << endl;
    } else {
        cout << "Lost" << endl;
    }
    return 0;
}