#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string a, b, c;
    cin >> N;
    cin >> a;
    cin >> b;
    cin >> c;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (a[i]==b[i] && b[i]==c[i]) {
            continue;
        } else if (a[i]!=b[i] && b[i]!=c[i] && c[i]!=a[i]) {
            count+=2;
        } else {
            count++;
        }
    }
    cout << count << '\n';
}
