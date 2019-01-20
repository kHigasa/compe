#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n,m,a,res=1;
    cin >> n >> m >> a;
    if(n%a==0) {
        res*=n/a;
    } else res*=(n/a+1);
    if (m%a==0) {
        res*=m/a;
    } else res*=(m/a+1);
    cout << res << '\n';
    return 0;
}
