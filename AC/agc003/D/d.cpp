#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    vector<ll> primes;
    for (ll i=2;i<=10000;++i) {
        bool flag=true;
        for (ll j=2;j*j<=i;++j) {
            if(i%j==0) {
                flag=false;
                break;
            }
        }
    }
    if(flag) primes.push_back(i);
    vactor<ll> triple;
    for(int i=0;i<primes.size();++i) {
        ll val=primes[i];
        triple.push_back(val*val*val);
    }
    ll N;
    cin >> N;
    vector<ll> s(N);
    map<vector<l_l>, ll> mp;
    map<int, vector<l_l> > mp2;
    for (int i=0;i<N;++i) {
        cin >> s[i];
        ll copy=s[i];
        vector<l_l> to_map;
        for (int j=0;j<primes.size();++j) {
            while(s[i]%triple[j]==0) {
                s[i]/=triple[j];
                copy/=triple[j];
            }
            ll tmp=0;
            if(s[i]%primes[j]==0) {
                copy/=primes[j];
                tmp=1;
            }
            if(s[i]%(primes[j]*primes[j])==0) {
                copy/=primes[j];
                tmp=2;
            }
            if(tmp>0) {
                to_map.push_back({j,tmp});
            }
        }
        if(copy>1) {
            ll ok=1000;
            ll ng=10000000000;
            while(ng-ok>1) {
                ll mid=(ok+ng)/2;
                if(mid*mid<=copy) {
                    ok=mid;
                }
                else {
                    ng=mid;
                }
            }
            if(copy%(ok*ok)==0) {
                to_map.push_back({ok,2});
            }
            else {
                to_map.push_back({copy, 1});
            }
        }
        mp[to_map]++;
        mp2[i]=to_map;
    }
    ll res=0;
    for(int i=0;i<s.size();++i) {
        if(s[i]==1) {
            vector<l_l> emp;
            if(mp[emp]>0) {
                ++res;
            }
            mp[emp]=0;
            continue;
        }
        vector<l_l> tmp=mp2[i];
        vector<l_l> rev;
        for(int j=0;j<tmp.size();++j) {
            l_l NEW=tmp[j];
            NEW.second=3-NEW.second;
            rev.push_back(NEW);
        }
        res+=max(mp[tmp],mp[rev]);
        mp[tmp]=0;
        mp[rev]=0;
    }
    cout << res << "\n";
    return 0;
}
