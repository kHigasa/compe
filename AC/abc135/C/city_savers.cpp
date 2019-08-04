#include <cstdio>
#include <algorithm>
#define rep(i, n) for (int i = 0; (i) < (int)(n); (i)++)

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int A[100005];
    rep(i, n + 1) scanf("%d", &A[i]);
    int B[100005];
    rep(i, n) scanf("%d", &B[i]);

    int ans = 0;
    rep(i, n) {
        ans += min(A[i], B[i]);
        B[i] -= A[i];
        if (B[i] > 0) {
            ans += min(A[i + 1], B[i]);
            A[i + 1] = max(A[i + 1] - B[i], 0);
        }
    }

    printf("%d\n", ans);
    return 0;
}
