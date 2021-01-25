#include <cstdio>
#include <vector>
#include <algorithm>
#define SIZE 2005

using namespace std;
typedef long long ll;

vector<int> T[SIZE];

// return node num where the depth <= k / 2
int dfs(int x, int p, int d, int mx) {
    int ans = 1;
    if (d != mx) {
        for (int y : T[x]) {
            if (y == p) continue;
            ans += dfs(y, x, d + 1, mx);
        }
    }
    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        T[a].push_back(b);
        T[b].push_back(a);
    }
    int ans = 0;
    if ((k & 1) == 0) {
        for (int i = 1; i <= n; i++) ans = max(ans, dfs(i, -1, 0, k / 2));
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j : T[i]) ans = max(ans, dfs(i, j, 0, k / 2) + dfs(j, i, 0, k / 2));
        }
    }
    ans = n - ans;
    printf("%d\n", ans);
    return 0;
}
