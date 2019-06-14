#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int DP[100005];
vector<int> E[100005];

void dfs(int a) {
    if (E[a].empty()) return;
    for (int i = 0; i < (int)E[a].size(); i++) dfs(E[a][i]);
    vector<int> TP;
    for (int i = 0; i < (int)E[a].size(); i++) TP.push_back(DP[E[a][i]]);
    sort(TP.begin(), TP.end());
    int mx = 0;
    for (int i = 0; i < (int)TP.size(); i++) mx = max(mx, TP[i] + (int)TP.size() - i);
    DP[a] = mx;
}

int main() {
    int n;
    scanf("%d", &n);
    int a;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &a);
        E[a].push_back(i);
    }
    dfs(1);
    printf("%d\n", DP[1]);
}
