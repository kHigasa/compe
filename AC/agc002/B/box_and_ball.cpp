#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> box(N, 1);
    vector<bool> possibility(N, false);
    possibility[0] = true;

    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        box[x]--; box[y]++;
        if (possibility[x]) possibility[y] = true;
        if (box[x] == 0) possibility[x] = false;
    }

    int res = 0;
    for (int i = 0; i < N; i++) {
        if (possibility[i]) res++;
    }
    printf("%d\n", res);

    return 0;
}
