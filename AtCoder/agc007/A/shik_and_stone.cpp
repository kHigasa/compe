#include <cstdio>

using namespace std;

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    int count = 0;
    char A[10][10];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%c", &A[i][j]);
            if (A[i][j] == '#') count++;
            if (count > H + W - 1) {
                puts("Impossible");
                return 0;
            }
        }
    }
    puts("Possible");
}

