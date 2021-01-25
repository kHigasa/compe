#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int A[100005];
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans++;
        while (i + 1 < n && A[i] == A[i + 1]) i++;
        if (i == n - 1) break;
        if (A[i] < A[i + 1]) {
            while (i + 1 < n && A[i] <= A[i + 1]) i++
        } else {
            while (i + 1 < n && A[i] >= A[i + 1]) i++
        }
    }
    printf("%d\n", ans);
    return 0;
}
