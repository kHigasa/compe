#include <cstdio>
#include <vector>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

int count;
vector<int> A(MAX), L(MAX/2+2), R(MAX/2+2);

void merge(vector<int> &A, int n, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++) L[i] = A[left+i];
	for (int i = 0; i < n2; i++) R[i] = A[mid+i];
	L[n1] = R[n2] = SENTINEL;
	int i = 0;
	int j = 0;
	for (int k = left; k < right; k++) {
		if (L[i] <= R[i]) {
			A[k] = L[i++];
		} else {
			A[k] = R[j++];
		}
		count++;
	}
}

void mergeSort(vector<int> &A, int n, int left, int right) {
	if (left+1 < right) {
		int mid = (left+right)/2;
		mergeSort(A, n, left, mid);
		mergeSort(A, n, mid, right);
		merge(A, n, left, mid, right);
	}
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);

	mergeSort(A, n, 0, n);

	for (int i = 0; i < n; i++) printf("%d ", A[i]);
	printf("\n");
	printf("%d", count);
	printf("\n");

	return 0;
}

