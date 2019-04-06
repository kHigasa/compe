#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ll a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    ll res;
    if ((a & 1) == 1 && (b & 1) == 1 && (c & 1) == 1) {
        res = min(a, b) * min(c, max(a, b));
    }
    else {
        res = 0;
    }

    printf("%lld\n", res);
}

