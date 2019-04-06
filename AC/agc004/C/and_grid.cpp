#include <cstdio>

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    const int N = 505;
    char a[N][N], r[N][N], b[N][N];
    for (int i = 0; i < H; ++i) {
        scanf("%s", a[i]);
        for (int j = 0; j < W; ++j) {
            if ((i & 1) == 0) {
                r[i][j] = a[i][j];
                b[i][j] = '#';
            } else {
                r[i][j] = '#';
                b[i][j] = a[i][j];
            }
        }
        r[i][0] = '#';
        r[i][W - 1] = '.';
        b[i][0] = '.';
        b[i][W - 1] = '#';
    }

    for (int i = 0; i < H; ++i) {
        puts(r[i]);
    }
    puts("");
    for (int i = 0; i < H; ++i) {
        puts(b[i]);
    }

    return 0;
}

