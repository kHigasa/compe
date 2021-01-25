#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    while(a) {
        b %= a;
        ll tmp = a; a = b; b = tmp;
    }
    return b;
}

int main() {
    ll n, x;
    scanf("%lld %lld", &n, &x);
    ll ans = (n - gcd(n, x)) * 3;
    printf("%lld\n", ans);
}
