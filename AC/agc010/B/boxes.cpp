#include <cstdio>

using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    ll pat_sum = n * (n + 1) / 2;
    int A[100005];
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        sum += A[i];
    }
    if (sum % pat_sum != 0) {
        puts("NO");
        return 0;
    }
    else {
        int iter = sum / pat_sum;
        int dif;
        for (int i = 0; i < n; i++) {
            dif = A[(i + 1) % n] - A[i] - iter;
            if (dif > 0 || (-dif % n) != 0) {
                puts("NO");
                return 0;
            }
        }
        puts("YES");
        return 0;
    }
}
