#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    int A[100005];
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    sort(A, A + n);
    ll S[100005];
    for (int i = 0; i < n; i++) {
        if (i == 0) S[i] = A[i];
        else S[i] = S[i - 1] + A[i];
    }
    int ans = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (2 * S[i] < A[i + 1]) break;
        else ans++;
    }
    printf("%d\n", ans);
    return 0;
}
