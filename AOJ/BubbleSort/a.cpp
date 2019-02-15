#include <iostream>
#include <vector>
using namespace std;
static const int MAX = 100;

int main() {
	int N;
	vector<int> A(MAX);
	bool flag = 1;

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	int tmp, count = 0;
	for (int i = 0; flag; i++) {
		flag = 0;
		for (int j = N-1; j > i; j--) {
			if (A[j] < A[j-1]) {
				tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
				flag = 1;
				count++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (i != N-1) {
			cout << A[i] << ' ';
		} else {
			cout << A[i] << '\n';
		}
	}

	cout << count << '\n';

	return 0;
}

