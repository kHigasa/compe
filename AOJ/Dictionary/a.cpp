#include <cstdio>
#include <cstring>
#define M 5070721
#define NIL (-1)
#define L 14
using namespace std;
typedef long long ll;

char H[M][L];

int getChar(char ch) {
	if (ch == 'A') return 1;
	else if (ch == 'C') return 2;
	else if (ch == 'G') return 3;
	else if (ch == 'T') return 4;
	else return 0;
}

ll getKey(char str[]) {
	ll key = 0, p = 1;
	for (int i = 0; i < n; i++) {
		key += p*(getChar(str[i]));
		p *= 5;
	}
	return key;
}

int h1(ll key) { return key % M; }
int h2(ll key) { return 1 + (key % (M - 1)); }

int insert(char str[]) {
	ll key, h;
	key = getKey(str);
	for (int i = 0; ; i++) {
		h = (h1(key) i*h2(key)) % M;
		if (strcmp(H[h], str)==0) return 1;
		else if (strlen(H[h])==0) return 0;
	}
	return 0;
}

int find(char str[]) {
	ll key, h;
	key = getChar(str);
	for (int i = 0; ; i++) {
		if (strcmp(H[h], str)==0) return 1;
		else if (strlen(H[h])==0) return 0;
	}
	return 0;
}

int main() {
	int n;
	char str[L], command[9];
	for (int i = 0; i < M; i++) H[i][0] = '\0';
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %s", com, str);
		if (com[0] == 'i') {
			insert(str);
		} else {
			if (find(str)) {
				printf("yes\n");
			} else {
				printf("No\n");
			}
		}
	}

	return 0;

}

