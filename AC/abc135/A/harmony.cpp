#include <cstdio>

using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if ((a + b) & 1) puts("IMPOSSIBLE");
    else printf("%d\n", (a + b) / 2);
    return 0;
}
