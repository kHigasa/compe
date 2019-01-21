#include <bits/stdc++.h>

using namespace std;

const int N = 555;

char s[N][N], a[N][N], c[N][N];
int x[N * N], y[N * N];
bool was[N][N];

int main() {
    int h, w;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < w; j++) {
            if (i % 2 == 0) {
                a[i][j] = s[i][j];
                c[i][j] = '#';
            } else {
                a[i][j] = '#';
                c[i][j] = s[i][j];
            }
        }
        a[i][0] = '#';
        a[i][w - 1] = '.';
        c[i][0] = '.';
        c[i][w - 1] = '#';
    }
    for (int i = 0; i < h; i++) {
        puts(a[i]);
    }
    puts("");
    for (int i = 0; i < h; i++) {
        puts(c[i]);
    }
    return 0;
}
