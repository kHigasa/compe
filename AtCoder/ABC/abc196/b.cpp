#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    vector<vector<char>> map(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> map [i][j];
        }
    }
    int ans = 1;
    for (int i = 0; i < w - y; i++) {
        if (map[x-1][y+i] != '#') {
            ans++;
        } else break;
    }
    for (int i = y - 2; i >= 0; i--) {
        if (map[x-1][i] != '#') {
            ans++;
        } else break;
    }
    for (int i = x - 2; i >= 0; i--) {
        if (map[i][y-1] != '#') {
            ans++;
        } else break;
    }
    for (int i = 0; i < h - x; i++) {
        if (map[x+i][y-1] != '#') {
            ans++;
        } else break;
    }
    cout << ans << endl;
    return 0;
}