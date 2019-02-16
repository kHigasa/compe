#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	stack<int> S1;
	stack<pair<int, int>> S2;
	char ch;
	int sum = 0;
	for (int i = 0; cin >> ch; i++) {
		if (ch == '\\') {
			S1.push(i);
		} else if (ch == '/' && S1.size() > 0) {
			int j = S1.top();
			sum += i-j;
			int a = i-j;
			while (S2.size() > 0 && S2.top().first > j) {
				a += S2.top().second;
				S2.pop();
			}
			S2.push(make_pair(j, a));
		}
	}

	vector<int> res;
	while (S2.size() > 0) {
		res.push_back(S2.top().second);
		S2.pop();
	}
	reverse(res.begin(), res.end());
	cout << sum << '\n';
	cout << res.size();
	for (int i = 0; i < res.size(); i++) {
		cout << " ";
		cout << res[i];
	}
	cout << '\n';

	return 0;
}

