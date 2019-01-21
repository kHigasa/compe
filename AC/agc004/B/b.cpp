#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> VLL;

int main() {
    ll N,x;
    cin >> N >> x;
    VLL vec,cp;
    for(int i=0;i<N;++i) {
        cin >> vec[i];
        cp[i]=vec[i];
    }
    ll res=0;
    for(int k=0;k<N;++k) {
        ll cost=x*k;
        for (int i=0;i<N;++i) {
            cp[i]=min(cp[i],vec[(i-k+N)%N]);
        }
        for (int i=0;i<N;++i) {
            cost+=cp[i];
        }
        res=min(res,cost);
    }
    cout << res << '\n';
    return 0;
}
