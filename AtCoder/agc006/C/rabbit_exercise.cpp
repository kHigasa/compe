// i couldn't understand

#include <cstdio>
#include <algorithm>
#define SIZE 100005

using namespace std;
typedef long long ll;

int main() {
    int N;
    scanf("%d", &N);
    int x[SIZE];
    for (int i = 0; i < N; i++) scanf("%d", &x[i]);
    int X[SIZE];
    for (int i = 0; i < N; i++) X[i] = i;
    int M;
    ll K;
    scanf("%d %lld", &M, &K);
    for (int i = 0; i < M; i++) {
        int a;
        scanf("%d", &a); a--;
        swap(X[a - 1], X[a]);
    }
    int T[SIZE], nd[SIZE];
    bool use[SIZE];
    for (int i = 0; i < N - 1; i++) {
        if (!use[i]) {
            int now = i;
            int len = 0;
            do {
                use[now] = true;
                nd[len++] = now;
                now = X[now];
            } while (now != i);
            for (int j = 0; j < len; j++) {
                int to = (int) (K % len);
                to = nd[(j + to) % len];
                T[nd[j]] = to;
            }
        }
    }
    ll sum = x[0];
    for (int i = 0; i < N; i++) {
        printf("%lld\n", sum);
        int pos = T[i];
        sum += x[pos + 1] - x[pos];
    }
    return 0;
}

