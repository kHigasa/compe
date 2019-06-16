#include <cstdio>

using namespace std;

int main() {
    int n, c, k;
    scanf("%d %d %d", &n, &c, &k);
    int T[100005];
    for (int i = 0; i < n; i++) scanf("%d", &T[i]);
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if (T[i] > T[j] + k || (i - j) == c) {
            ans++;
            j = i;
        }
    }
    ans++;
    printf("%d\n", ans);
    return 0;
}
