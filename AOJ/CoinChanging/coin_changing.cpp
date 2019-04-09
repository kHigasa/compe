#include <cstdio>
#include <algorithm>
using namespace std;
#define INF (1e9)

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int c[m + 1];
    int t[n + 1];
    for (int i = 1; i <= m; ++i) scanf("%d", &c[i]);
    for (int i = 1; i <= n; ++i) t[i] = INF;
    t[0] = [0];

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j + c[i] <= n; ++j) {
            t[j + c[i]] = min(t[j + c[i]], t[j] + 1);
        }
    }

    printf("%d\n", t[n]);
}

