#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, a, b, Max, Min;
    cin >> N >> a >> b;
    Max = min(a, b);
    if (a+b>N) {
        Min = a+b-N;
    } else {
        Min = 0;
    }
    cout << Max << ' ' << Min << '\n';
}
