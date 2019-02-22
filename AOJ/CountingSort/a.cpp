#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
#define MAX 2000001
#define VMAX 10001

int main() {
	int n;
	vector<int> A(MAX), B(MAX), C(VMAX, 0);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d", &A[i]);
		C[A[i]]++;
	}

	for (int i = 1; i < VMAX; i++) C[i] = C[i] + C[i-1];

	for (int j = 1; j <= n; j++) {
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}

	for (int i = 1; i <= n; i++) {
		if (i > 1) printf(" ");
		printf("%d", B[i]);
	}
	printf("\n");

	return 0;
}

