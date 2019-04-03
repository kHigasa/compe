#include <cstdio>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > 0) {
        puts("Positive");
    } else if (a <= 0 && b >= 0) {
        puts("Zero");
    } else {
        puts((a - b) & 1 ? "Positive": "Negative");
    }
    return 0;
}
