#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n, q, t;
	vector<int> S(10000);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &S[i]);

	scanf("%d", &q);
	int count = 0;
	for (int i = 0; i < q; i++) {
		scanf("%d", &t);
		S[n] = t;
		int j = 0;
		while (S[j] != t) j++;
		if (j != n) count++;
	}

	printf("%d\n", count);

	return 0;
}
