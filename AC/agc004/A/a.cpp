#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ll a,b,c,res;
    cin >> a >> b >> c;
    if(a%2==1&&b%2==1&&c%2==1) {
        res=min(a,b)*min(c,max(a,b));
    }
    else {
        res=0;
    }
    cout << res << '\n';
    return 0;
}
