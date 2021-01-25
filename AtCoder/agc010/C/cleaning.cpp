#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int A[100005];
vector<int> E[100005];

ll dfs(int x, int p = -1) {
    ll sum = 0, mx = 0;
    if (p != -1) E[x].erase(find(E[x].begin(), E[x].end(), p));
    for (int y : E[x]) {
        ll t = dfs(y, x);
        if (t == -1) return -1;
        mx = max(mx, t);
        sum += t;
    }
    if (E[x].empty()) return A[x];
    if (2 * A[x] < sum || sum < A[x] || A[x] < mx) return -1;
    if (p != -1) return 2 * A[x] - sum;
    else {
        if (E[x].size() == 1) return (A[x] == sum) ? 0 : -1;
        else return (2 * A[x] == sum) ? 0 : -1;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    ll res = dfs(0);
    puts(res == -1 ? "NO" : "YES");
    return 0;
}
