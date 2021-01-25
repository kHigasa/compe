#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;

int main() {
    int N;
    scanf("%d", &N);
    int a[N], ra[N + 1];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
        ra[a[i]] = i;
    }

    ll ans = 0;
    set<int> s;
    s.insert(-1); s.insert(N);
    for (int d = 1; d <= N; ++d) {
        int i = ra[d];
        auto it = s.lower_bound(i);
        int r = *it;
        it--;
        int l = *it;
        ans += ll(d) * (i - l) * (r - i);
        s.insert(i);
    }

    printf("%lld\n", ans);
}

