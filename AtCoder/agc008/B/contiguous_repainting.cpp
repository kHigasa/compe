#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int A[100005];
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    ll sum = 0;
    ll p[100005];
    for (int i = 0; i < n; i++) {
        sum += max(0, A[i]);
        p[i] = sum;
    }
    sum = 0;
    ll s[100005];
    for (int i = n - 1; i >= 0; i--) {
        sum += max(0, A[i]);
        s[i] = sum;
    }
    sum = 0;
    for (int i = 0; i < k; i++) sum += A[i];
    ll ans = max(sum, 0ll) + s[k];
    for (int i = k; i < n; i++) {
        sum += A[i];
        sum -= A[i - k];
        ans = max(ans, max(sum, 0ll) + p[i - k] + s[i + 1]);
    }
    printf("%lld\n", ans);
    return 0;
}
