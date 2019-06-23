#include <cstdio>
#define rep(i, n) for (int i = 0; (i) < (int)(n); (i)++)

using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b && b == c && c == a) {
        puts("-1");
        return 0;
    }
    rep(i, 100) {
        if ((a & 1) != 0 || (b & 1) != 0 || (c & 1) != 0) {
            printf("%d\n", i);
            break;
        }
        int tmp_a = (b + c) / 2, tmp_b = (c + a) / 2, tmp_c = (a + b) / 2;
        a = tmp_a; b = tmp_b; c = tmp_c;
    }
    return 0;
}
