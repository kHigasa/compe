#include <cstdio>
using namespace std;

int main() {
    int N, x;
    int ans[20005];
    scanf("%d %d", &N, &x);
    if (x == 1 || x == 2 * N - 1) {
        puts("No");
    } else {
        ans[N - 1] = x;
        int pos = N - 2;
        for (int i = 0; i < 2 * N - 2; i++) {
            if (x <= 1) x = 2 * N;
            ans[pos] = --x;
            pos--;
            if (pos < 0) pos = 2 * N - 2;
        }
        puts("Yes");
        for (int i = 0; i < 2 * N - 1; i++) printf("%d\n", ans[i]);
    }

    return 0;
}

