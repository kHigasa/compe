#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int N;
    ll x;
    scanf("%d %lld", &N, &x);
    ll a[2005], copy[2005];
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &a[i]);
        copy[i] = a[i];
    }

    ll res = 0;
    for (int i = 0; i < N; ++i) {
        ll cost = x * i;
        for (int j = 0; j < N; ++j) {
            copy[j] = min(copy[j], a[(j - i + N) % N]);
        }
        for (int j = 0; j < N; ++j) {
            cost += copy[j];
        }
        if (i == 0) res = cost;
        else res = min(res, cost);
    }

    printf("%lld\n", res);
}

