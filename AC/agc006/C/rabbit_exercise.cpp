// ref this submission (https://atcoder.jp/contests/agc006/submissions/954907) .
// editting....

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
}

