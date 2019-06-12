#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int L[205];
    for (int i = 0; i < n * 2; i++) scanf("%d", &L[i]);
    sort(L, L + n * 2);
    int ans = 0;
    for (int i = 0; i < n; i++) ans += L[i * 2];
    printf("%d\n", ans);
    return 0;
}
