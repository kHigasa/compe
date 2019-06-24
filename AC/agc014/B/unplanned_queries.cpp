#include <cstdio>
#define rep(i, n) for (int i = 0; (i) < (int)(n); (i)++)

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b;
    int C[100005];
    rep(i, m) {
        scanf("%d %d", &a, &b);
        a--; b--;
        C[a]++; C[b]++;
    }
    rep(i, n) {
        if ((C[i] & 1) != 0) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
