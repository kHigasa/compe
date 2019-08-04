#include <cstdio>
#define rep(i, n) for (int i = 0; (i) < (int)(n); (i)++)

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int p, cnt = 0;
    rep(i, n) {
        scanf("%d", &p);
        if ((p - 1) != i) cnt++;
        if (cnt > 2) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
