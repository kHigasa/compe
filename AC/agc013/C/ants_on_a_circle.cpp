#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int n, l, t;
    scanf("%d %d %d", &n, &l, &t);
    int X[100005], W[100005];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &W[i]);
        if (W[i] == 2) W[i] = -1;
    }
    pair<int, int> pr[100005];
    for (int i = 0; i < n; i++) pr[i] = make_pair(X[i], i);
    sort(pr, pr + n);
    vector<ll> vec;
    ll nc = 0;
    for (int i = 0; i < n; i++) {
        ll pos = X[i] + W[i] * t;
        ll fpos = ((pos % l) + l) % l;
        ll g = pos > 0 ? pos / l : (pos - l + 1) / l;
        nc += g;
        vec.push_back(fpos);
    }
    nc = ((nc % n) + n) % n;
    sort(vec.begin(), vec.end());
    int ans[100005];
    for (int i = 0; i < n; i++) ans[pr[i].second] = vec[(i + nc) % n];
    for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
    return 0;
}
