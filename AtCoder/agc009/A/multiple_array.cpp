#include <cstdio>

using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    int A[100005], B[100005];
    for (int i = 0; i < n; i++) scanf("%d %d", &A[i], &B[i]);
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int cur = (A[i] + ans) % B[i];
        if (cur != 0) ans += B[i] - cur;
    }
    printf("%lld\n", ans);
    return 0;
}
