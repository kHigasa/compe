#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#define SIZE 505

using namespace std;
typedef pair<int, int> pii;

int main() {
    int n;
    scanf("%d", &n);
    int x[SIZE];
    vector<pii> v;
    int a[100000];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        v.push_back(make_pair(x[i], i));
        a[x[i]] = i;
    }
    sort(v.begin(), v.end());
    int pt;
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j < v[i].second - 1; j++) {
            do {
                if (a[pt] == 0) {
                    if (pt <= v[i].first) {
                        printf("No\n");
                        return 0;
                    }
                    a[pt] = v[i].second;
                    pt++;
                    break;
                }
                pt++;
            } while (true);
        }
    }
    reverse(v.begin(), v.end());
    pt = n * n;
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j < n - v[i].second; j++) {
            do {
                if (a[pt] == 0) {
                    if (pt <= v[i].first) {
                        printf("No\n");
                        return 0;
                    }
                    a[pt] = v[i].second;
                    pt--;
                    break;
                }
                pt--;
            } while (true);
        }
    }
    printf("Yes\n");
    for (int i = 1; i <= n * n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
