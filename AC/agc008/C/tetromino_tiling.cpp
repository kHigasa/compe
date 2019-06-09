#include <cstdio>

using namespace std;
typedef long long ll;

int main() {
    int i, o, t, j, l, s, z;
    scanf("%d %d %d %d %d %d %d", &i, &o, &t, &j, &l, &s, &z);
    ll k = o;
    if ((i && j && l) && ((i & 1) + (j & 1) + (l & 1)) == 3) {
        k += 3;
        --i; --j; --l;
    }
    k += 2 * i / 2;
    k += 2 * j / 2;
    k += 2 * l / 2;
    printf("%lld\n", k);
    return 0;
}
