#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll a, b, count;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b;
    if (a>0) {
	puts("Positive");
    } else if (a==0) {
	puts("Zero");
    } else {
	if (b>=0) {
            puts("Zero");
	} else {
	    count=b-a+1;
	    if (count%2==0) {
		puts("Positive");
	    } else {
		puts("Negative");
	    }
	}
    }
    return 0;
}
