#include <cstdio>

using namespace std;
typedef long long ll;

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    int a[N];
    for (int i = 0; i < N; ++i) scanf("%d", &a[i]);

    ll threshold = 0;
    int id = 0;
    for (int i = 0; i < N - 1; ++i) {
        ll tmp = a[i] + a[i + 1];
        if (tmp > threshold) {
            threshold = tmp;
            id = i;
        }
    }
    if (threshold < L) puts("Impossible");
    else puts("Possible");

    for (int i = 0; i < id; ++i) printf("%d\n", i + 1);
    for (int i = N - 2; i > id; --i) printf("%d\n", i + 1);
    printf("%d\n", id + 1);

    return 0;
}

