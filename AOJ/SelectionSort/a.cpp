#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
static const int MAX = 100;

int main() {
	int N;
	vector<int> A(MAX);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	int tmp, count = 0;
	for (int i = 0; i < N-2; i++) {
		int lead = i+1;
		for (int j = i+2; j < N; j++) {
			if (A[j] < A[lead]) lead = j;
		}
		tmp = A[i];
		A[i] = A[lead];
		A[lead] = tmp;
		count++;
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

