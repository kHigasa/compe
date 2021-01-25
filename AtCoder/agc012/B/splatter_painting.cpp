#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b;
    vector<int> gph[100005];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        gph[a].push_back(b);
        gph[b].push_back(a);
    }
    int q;
    scanf("%d", &q);
    int v, d;
    int C[100005];
    int dp[15][100005];
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &v, &d, &C[i]);
        v--;
        dp[d][v] = i + 1;
    }
    for (int i = 9; i >= 0; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = max(dp[i][j], dp[i + 1][j]);
            for (int k : gph[j]) dp[i][j] = max(dp[i][j], dp[i + 1][k]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (dp[0][i] == 0) printf("%d\n", 0);
        else printf("%d\n", C[dp[0][i]] - 1);
    }
    return 0;
}
