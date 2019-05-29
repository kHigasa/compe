#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    string s, t;
    cin >> N >> s >> t;

    for (int i = 0; i < N; i++) {
        if (s.substr(i) == t.substr(0, N - i)) {
            cout << (s + t.substr(N - i)).size() << "\n";
            return 0;
        }
    }
}

