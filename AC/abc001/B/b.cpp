#include <iostream>

using namespace std;

int main() {
    int m;

    cin >> m;

    if (m >= 0 && m < 100) {
        cout << 0 << 0 << '\n';
    } else if (m >= 100 && m <= 5000) {
        m = (m * 10) / 1000;
        if ((m / 10) < 1) {
            cout << 0 << m << '\n';
        } else {
            cout << m << '\n';
        }
    } else if (m >= 6000 && m <= 30000) {
        cout << (m + 50000) / 1000 << '\n';
    } else if (m >= 35000 && m <= 70000) {
        cout << ((m - 30000) / 5 + 80000) / 1000 << '\n';
    } else if (m > 70000 && m <= 100000) {
        cout << 89 << '\n';
    } else {
        cerr << "Invalid value\n";
    }

    return 0;
}
