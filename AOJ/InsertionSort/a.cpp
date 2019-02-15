#include <iostream>
#include <vector>
using namespace std;
static const int MAX = 100;

int main() {
	int N;
	vector<int> A(MAX);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	for (int i = 0; i < N; i++) {
		if (i != N-1) {
			cout << A[i] << ' ';
		} else {
			cout << A[i] << '\n';
		}
	}

	int tmp;
	for (int i = 1; i < N; i++) {
		int j = i;
		while (A[j-1] > A[j] && j > 0) {
			tmp = A[j];
			A[j] = A[j-1];
			A[j-1] = tmp;
			j--;
		}
		for (int i = 0; i < N; i++) {
			if (i != N-1) {
				cout << A[i] << ' ';
			} else {
				cout << A[i] << '\n';
			}
		}
	}

	return 0;
}

