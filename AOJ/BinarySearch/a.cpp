#include <cstdio>
#include <vector>
using namespace std;
static const int MAX = 100000;

int main() {
	int n, q, t;
	vector<int> S(MAX);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &S[i]);

	scanf("%d", &q);
	int left = 0, right = n, count = 0;
	for (int i = 0; i < q; i++) {
		scanf("%d", &t);
		while (left < right) {
			int mid = (left+right) / 2;
			if (t == S[mid]) {
				count++;
				break;
			} else if (t < S[mid]) {
				right = mid;
			} else if (t > S[mid]) {
				left = mid+1;
			}
		}
	}

	printf("%d\n", count);

	return 0;
}

