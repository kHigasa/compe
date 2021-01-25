#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int P[20005];
    int A[20005], B[20005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &P[i]);
        A[i] = (i + 1) * n;
        B[i] = (n - i) * n;
    }
    for (int i = 0; i < n; i++) A[P[i]] += i;
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
    for (int i = 0; i < n; i++) printf("%d ", B[i]);
    printf("\n");
    return 0;
}

