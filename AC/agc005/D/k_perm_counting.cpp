#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;

const int mod = 924844033;

inline void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

inline int mul(int a, int b) {
    return (ll) a * b % mod;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int fact[N];
    fact[0] = 1;
    for (int i = 0; i < N; ++i) fact[i] = mul(fact[i - 1], i);

    int total = 0;
    int res[N], new_res[N];
    int can_right[N], can_left[N];
    int f[N][N][2];
    int cur[N];
    res[0] = 1;
    for (int r = 0; r < 2 * K && r < N; ++r) {
        int m = 0;
        for (int i = r; i < N; i += 2 * K) {
            can_left[m] = (i - K >= 0);
            can_right[m] = (i + K < N);
            m++;
        }
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int t = 0; t < 2; ++t) {
                    f[i][j][t] = 0;
                }
            }
        }
        f[0][0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <= i; ++j) {
                for (int t = 0; t < 2; ++t) {
                    int ft = f[i][j][t];
                    if (ft == 0) continue;
                    add(f[i + 1][j][0], ft);
                    if (can_left[i] && t == 0) add(f[i + 1][j + 1][0], ft);
                    if (can_right[i]) add(f[i + 1][j + 1][1], ft);
                }
            }
        }
        for (int j = 0; j <= m; ++j) cur[j] = (f[m][j][0] + f[m][j][1]) % mod;
        for (int i = 0; i <= total + m; ++i) new_res[i] = 0;
        for (int i = total; i >= 0; --i) {
            for (int j = 0; j <= m; ++j) {
                add(new_res[i + j], mul(res[i], cur[j]));
            }
        }
        total += m;
        for (int i = 0; i <= total; ++i) {
            res[i] = new_res[i];
        }
    }

    int ans = 0, val;
    for (int i = 0; i <= total; ++i) {
        val = mul(res[i], fact[N - i]);
        add(ans, (i & 1) == 0 ? val : (mod - val));
    }

    printf("%d\n", ans);
}

