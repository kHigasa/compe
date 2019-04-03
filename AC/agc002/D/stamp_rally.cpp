#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct disjoint_set {
    int path[100005], size[100005];
    void init(int N) {
        for (int i = 1; i <= N; ++i) {
            path[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        return path[x] = (path[x] == x ? x : find(path[x]));
    }

    int get_size(int x) {
        return size[find(x)];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        path[y] = x;
        size[x] += size[y];
        return 1;
    }
} disj;

int main() {
    int N, M, Q;
    int a[100005], b[100005], x[100005], y[100005], z[100005];
    int bx[100005], by[100005];
    scanf("%d %d", &N, &M);
    for (int i = 0; i< M; ++i) scanf("%d %d", &a[i], &b[i]);
    scanf("%d", &Q);
    for (int i = 0; i< Q; ++i) {
        scanf("%d %d %d", &x[i], &y[i], &z[i]);
        bx[i] = 0, by[i] = M - 1;
    }

    vector<int> idx;
    for (int i = 0; i < Q; ++i) idx.push_back(i);

    for (int i = 0; i < 20; ++i) {
        sort(idx.begin(), idx.end(), [&](const int &a, const int &b) {
            return (bx[a] + by[a]) / 2 < (bx[b] + by[b]) / 2;
        });
        disj.init(N);
        int p = 0;
        for (auto &i : idx) {
            while (p <= (bx[i] + by[i]) / 2) {
                disj.unite(a[p], b[p]);
                p++;
            }
            if (bx[i] == by[i]) continue;
            int hamsu = disj.get_size(x[i]) + disj.get_size(y[i]);
            if (disj.find(x[i]) == disj.find(y[i])) hamsu /= 2;
            if (hamsu < x[i]) {
                bx[i] = (bx[i] + by[i]) / 2 + 1;
            } else {
                bx[i] = (bx[i] + by[i]) / 2;
            }
        }
    }

    for (int i = 0; i < Q; ++i) printf("%d\n", bx[i] + 1);

    return 0;
}
