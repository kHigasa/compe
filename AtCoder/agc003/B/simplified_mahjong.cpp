#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int N, A;
    scanf("%d", &N);
    int tmp = 0, res = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A);
        if(A != 0) {
            tmp += A;
        }
        else {
            res += abs(tmp/2);
            tmp = 0;
        }
    }
    res += abs(tmp/2);

    printf("%d\n", res);
}

