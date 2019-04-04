#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

int main() {
    vector<ll> primes;
    bool flag = true;
    for (ll i = 2; i <= 10000; ++i) {
        for (ll j = 2; j*j <= i; ++j) {
            if(i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) primes.push_back(i);
    }

    vll cubes;
    for (unsigned int i = 0; i < primes.size(); ++i) {
        ll val = primes[i];
        cubes.push_back(val*val*val);
    }

    ll N;
    scanf("%lld", &N);
    vll s(N);
    map<vector<pll>, ll> mp;
    map<int, vector<pll>> mp2;
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &s[i]);
        ll copy = s[i];
        vector<pll> power_map;
        for (unsigned int j = 0; j < cubes.size(); ++j) {
            while (s[i] % cubes[j] == 0) {
                s[i] /= cubes[j];
                copy /= cubes[j];
            }
            int power = 0;
            if (s[i] % primes[j] == 0) {
                copy /= primes[j];
                power = 1;
            }
            if (s[i] % (primes[j] * primes[j]) == 0) {
                copy /= primes[j];
                power = 2;
            }
            if (power > 0) {
                power_map.push_back({j, power});
            }
        }
        if (copy > 1) {
            ll ok=1000;
            ll ng=10000000000;
            while (ng - ok > 1) {
                ll mid = (ok + ng) / 2;
                if(mid * mid <= copy) ok = mid;
                else ng = mid;
            }
            if (copy % (ok * ok) == 0) power_map.push_back({ok, 2});
            else power_map.push_back({copy, 1});
        }
        mp[power_map]++;
        mp2[i]=power_map;
    }

    ll res = 0;
    for (unsigned int i = 0; i < s.size(); ++i) {
        if (s[i] == 1) {
            vector<pll> emp;
            if (mp[emp] > 0) {
                ++res;
            }
            mp[emp] = 0;
            continue;
        }
        vector<pll> tmp = mp2[i];
        vector<pll> rev;
        for(unsigned int j = 0; j < tmp.size(); ++j) {
            pll NEW = tmp[j];
            NEW.second = 3 - NEW.second;
            rev.push_back(NEW);
        }
        res += max(mp[tmp], mp[rev]);
        mp[tmp] = 0;
        mp[rev] = 0;
    }

    printf("%lld\n", res);
}
