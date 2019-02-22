#include <cstdio>
#include <vector>
using namespace std;
#define MAX 100000
#define SENTINEL 2000000000

struct Card {
	char suit;
	int value;
}

vector<Card> A(MAX), L(MAX/2+2), R(MAX/2+2);

void merge(vector<Card> &A, int n, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++) L[i] = A[left+i];
	for (int i = 0; i < n2; i++) R[i] = A[mid+i];
	L[n1].value = R[n2].value = SENTINEL;
	int i = 0, j = 0;
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

int partition(vector<Card> &A, int n, int p, int r) {
	struct Card x = A[r];
	int i = p-1;
	struct Card tmp;
	for (int j = p; j < r; j++) {
		if (A[j].value <= x.value) {
			i++;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	tmp = A[i+1];
	A[i+1] = A[r];
	A[r] = tmp;
	return i+1;
}

void quickSort(vector<Card> &A, int n, int p, int r) {
	if (p < r) {
		int q = partition(A, n, p, r);
		quickSort(A, n, p, q-1);
		quickSort(A, n, q+1, r);
	}
}

int main() {
	int n, v;
	vector<Card> A(MAX), B(MAX);
	char S[10];
	int stable = 1;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d", S, &v);
		A[i].suit = B[i].suit = S[0];
		A[i].value = B[i].value = v;
	}

	mergeSort(A, n, 0, n);
	quickSort(B, n, 0, n-1);

	for (int i = 0; i < n; i++) {
		if (A[i].suit != B[i].suit) stable = 0;
	}

	if (stable) printf("Stable\n");
	else printf("Not stable\n");
	for (int i = 0; i < n; i++) {
		printf("%c %d\n", B[i].suit, B[i].value);
	}

	return 0;
}

