#include <cstdio>
#include <vector>
using namespace std;
#define MAX 100000

int main() {
	int n;
	vector<int> A(MAX);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", A[i]);

	int x = A[n-1];
	int i = -1;
	int tmp;
	for (int j = 0; j < n-1; j++) {
		if (A[j] <= x) {
			i++;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	tmp = A[i+1];
	A[i+1] = A[n-1];
	A[n-1] = tmp;

	for (int k = 0; k < n; k++) {
		if (k) printf(" ");
		if (k == i+1) printf("[");
		printf("%d", A[k]);
		if (k == i+1) printf("]");
	}
	printf("\n");

	return 0;
}

