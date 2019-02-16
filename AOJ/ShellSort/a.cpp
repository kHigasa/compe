#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
static const int MAX = 1000000;

int main() {
	int n;
	ll count = 0;
	vll A(MAX);
	vll G;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);

	//Generate g
	int g;
	for (int i = 0; i < n; i++) {
		g = 3*i + 1;
		if (g > n) break;
		G.push_back(g);
	}

	for (int i = G.size()-1; i >= 0; i--) {
		int tmp;
		for (int j = G[i]; j < n; j+=G[i]) {
			while (A[j-G[i]] > A[j]) {
				tmp = A[j];
				A[j] = A[j-G[i]];
				A[j-G[i]] = tmp;
				count++;
			}
		}
	}

	printf("%d\n", G.size());
	for (int i = G.size()-1; i >= 0; i--) {
		printf("%d", G[i]);
		if ( i ) printf(" ");
	}
	printf("\n");
	printf("%d\n", count);
	for (int i = 0; i < n; i++) printf("%d\n", A[i]);

	return 0;
}

