#include <cstdio>
#include <algorithm>
#include <vector>
#define SIZE 100005

using namespace std;

int n, m, sz, R[SIZE];
bool V[SIZE];
vector<int> gph[SIZE];

void dfs(int x) {
    if (!V[x]) R[sz++] = x;
    V[x] = 1;
    for (int i : gph[x]) {
        if (!V[i]) {
            dfs(i);
            break;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        gph[a].push_back(b);
        gph[b].push_back(a);
    }
    dfs(0);
    reverse(R, R + sz);
    dfs(0);
    printf("%d\n", sz);
    for (int i = 0; i < sz; i++) printf("%d ", R[i] + 1);
    printf("\n");
    return 0;
}
