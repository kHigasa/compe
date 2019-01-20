#include <iostream>
#include <string>

using namespace std;

int main() {
    int deg, dis;
    int w;
    string dir;
    int i;

    cin >> deg >> dis;

    const string DIR[16] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
    const int W[13] = {0, 15, 93, 201, 327, 477, 645, 831, 1029, 1245, 1467, 1707, 1959};

    dir = DIR[((deg * 10 + 1125) / 2250) % 16];

    i = 0;
    while (true) {
        if (dis >= W[i] && dis < W[i+1]) {
            w = i;
            if (w == 0) {
                dir = "C";
                cout << dir << " " << w << '\n';
                break;
            }

            cout << dir << " " << w << '\n';
            break;
        }

        ++i;

        if (i == 12) {
            cout << dir << " " << 12 << '\n';
            break;
        }
    }

    return 0;
}
