#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, M, x, y;
    cin >> N >> M;
    vector<int> box(N, 1);
    vector<bool> possibility(N, false);
    possibility[0] = true;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        box[x]--; box[y]++;
        if (possibility[x]) possibility[y] = true;
        if (box[x]==0) possibility[x] = false;
    }

    ll res = 0;
    for (int i = 0; i < N; i++) {
        if (possibility[i]) res++;
    }
    cout << res << '\n';
    return 0;
}
