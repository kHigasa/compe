#include <cstdio>
#define rep(i, n) for (int i = 0; (i) < (int)(n); (i)++)
#define abs(x) ((x) > 0 ? (x) : -(x))
#define neg(x) (((x) == 1) ? 1 : -1)

using namespace std;
typedef long long ll;

int main() {
    int k, x, y;
    scanf("%d\n%d %d", &k, &x, &y);
    if (!(k & 1) && (x + y & 1)) {
        puts("-1");
        return 0;
    }
    int sz = 0;
    int ans_x[200010], ans_y[200010];
    int px = 0, py = 0;
    while (abs(px - x) + abs(py - y) > k * 2) {
        if (abs(px - x) > k) px += (px > x) ? -k : k;
        else py += (py > y) ? -k : k;
        ans_x[++sz] = px, ans_y[++sz] = py;
    }
    if (abs(px - x) + abs(py - y) != k) {
        if ((k & 1) && (x - px + y - py & 1)) {
            if (abs(py - y) <= k) {
                px += (k - abs(py - y)) * neg(px < x);
                py = y;
            } else {
                py += (k - abs(px - x)) * neg(py < y);
                px = x;
            }
            ans_x[++sz] = px, ans_y[++sz] = py;
        }
        int t = k * 2 - abs(px - x) - abs(py - y) >> 1;
        if (abs(px - x) < abs(py - y)) {
            if (px <= x) {
                ans_x[++ sz] = x + t;
                ans_y[sz] = py + (k - (x + t - px)) * neg(py < y);
            } else {
                ans_x[++ sz] = x - t;
                ans_y[sz] = py + (k - (px + t - x)) * neg(py < y); 
            }
        } else {
            if (py <= y) {
                ans_y[++ sz] = y + t;
                ans_x[sz] = px + (k - (y + t - py)) * neg(px < x);
            } else {
                ans_y[++ sz] = y - t;
                ans_x[sz] = px + (k - (py + t - y)) * neg(px < x);
            }
        }
    }
    ans_x[++sz] = x, ans_y[++sz] = y;
    printf("%d\n", sz);
    for (int i = 1; i <= sz; i++) printf("%d %d\n", ans_x[i], ans_y[i]);
    return 0;
}
