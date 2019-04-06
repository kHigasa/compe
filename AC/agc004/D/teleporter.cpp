#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int K, ans = 0;
vector<int> tree[100005];

int dfs(int node, int parent) {
    int depth = 0;
    for (unsigned int i = 0; i < tree[node].size(); ++i) depth = max(depth, dfs(tree[node][i], node));
    if (depth == K - 1 && parent != 0) {
        ans++;
        return 0;
    } else return depth++;
}

int main() {
    int N, a;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a);
        if (i == 0 && a != 1) ans++;
        tree[a].push_back(i);
    }

    dfs(0, 0);

    printf("%d\n", ans);
}

