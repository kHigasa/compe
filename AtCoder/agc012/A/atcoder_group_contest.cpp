#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    int A[300005];
    for (int i = 0; i < 3 * n; i++) scanf("%d", &A[i]);
    sort(A, A + 3 * n);
    ll ans = 0;
    for (int i = n; i < 3 * n; i += 2) ans += 1ll * A[i];
    printf("%lld\n", ans);
    return 0;
}
