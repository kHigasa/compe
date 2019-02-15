#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
static const int MAX = 200000;

int main() {
	vector<int> R(MAX);
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> R[i];

	int res = -2000000000;
	int r_min = R[0];

	for (int i = 1; i < n; i++) {
		r_min = min(r_min, R[i]);
		res = max(res, R[i] - r_min);
	}

	cout << res << '\n';
}

