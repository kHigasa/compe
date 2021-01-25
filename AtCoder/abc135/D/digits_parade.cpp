#include <cstdio>
#include <cstring>
#define rep(i, n) for (int i = 0; (i) < (int)(n); (i)++)

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
    char S[100005];
    scanf("%s", S);
    int n = strlen(S);

    int dp[100005][13];
    dp[0][0] = 1;
    rep(i, n) {
        int c;
        if (S[i] == '?') c = -1;
        else c = S[i] - '0';
        rep(j, 10) {
            if (c != -1 && c != j) continue;
            rep(k, 13) {
                dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
            }
        }
        rep(j, 13) dp[i + 1][j] %= MOD;
    }
    int ans = dp[n][5];

    printf("%d\n", ans);
    return 0;
}
