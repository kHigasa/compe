#include <cstdio>

using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    ll a, sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a);
        sum += a;
    }
    if ((sum & 1) == 0) puts("YES");
    else puts("NO");
    return 0;
}
