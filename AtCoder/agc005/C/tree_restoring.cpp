#include <cstdio>

void die() {
    printf("Impossible\n");
    exit(0);
}

int main() {
    int N, a;
    scanf("%d", &N);
    int max_dis = 1;
    int ra[105] = {};
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a);
        ra[a]++;
        if (a > max_dis) max_dis = a;
    }

    int min_dis;
    if ((max_dis & 1) == 0) {
        min_dis = max_dis / 2;
        ra[min_dis]--;
        if (ra[min_dis] != 0) die();
    } else {
        min_dis = max_dis / 2 + 1;
        ra[min_dis] -= 2;
        if (ra[min_dis] != 0) die();
    }

    for (int i = 1; i < min_dis; ++i) {
        if (ra[i] != 0) {
            printf("Impossible\n");
            exit(0);
        }
    }

    for (int i = min_dis + 1; i <= max_dis; ++i) {
        ra[i] -= 2;
        if (ra[i] < 0) die();
    }

    printf("Possible\n");
}

