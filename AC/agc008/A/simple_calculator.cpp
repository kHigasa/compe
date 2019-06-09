#include <cstdio>
#include <algorithm>

using namespace std;

int dis(int x, int y) {
    if (x <= y) return y - x;
    else return 2000000005;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", min(min(dis(x, y), dis(-x, y) + 1), dis(-x, -y) + 2));
    return 0;
}
