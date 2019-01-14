#include <iostream>

int main() {
    int m;

    std::cin >> m;

    if (m >= 0 && m < 100) {
        std::cout << 0 << 0 << '\n';
    } else if (m >= 100 && m <= 5000) {
        m = (m * 10) / 1000;
        if ((m / 10) < 1) {
            std::cout << 0 << m << '\n';
        } else {
            std::cout << m << '\n';
        }
    } else if (m >= 6000 && m <= 30000) {
        std::cout << (m + 50000) / 1000 << '\n';
    } else if (m >= 35000 && m <= 70000) {
        std::cout << ((m - 30000) / 5 + 80000) / 1000 << '\n';
    } else if (m > 70000 && m <= 100000) {
        std::cout << 89 << '\n';
    } else {
        std::cerr << "Invalid value\n";
    }

    return 0;
}
