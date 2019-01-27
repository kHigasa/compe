#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef map<ll, ll> mll;

int main() {
    ll N;
    cin >> N;
    vll va(N), vb(N);
    mll ma, mb;
    for (int i = 0; i < N; i++) {
        cin >> va[i] >> vb[i];
        ma.insert(make_pair(va[i], i));
        mb.insert(make_pair(vb[i], i));
    }
    ll tmpa = 0, tmpb = 0;
    for (int i = 0; i < N; i++) {
        if (i%2==0) {
            ll maxa = *max_element(va.begin(), va.end());
            tmpa+=maxa;
            size_t va_size = va.size();
            size_t maxa_el_count = std::count(va.begin(), va.end(), maxa);
            if (va_size==maxa_el_count) {
                ll maxb = *max_element(vb.begin(), vb.end());
                va.erase(va.begin()+mb.at(maxb));
                vb.erase(vb.begin()+mb.at(maxb));
            } else {
                va.erase(va.begin()+ma.at(maxa));
                vb.erase(vb.begin()+ma.at(maxa));
            }
        } else {
            ll maxb = *max_element(vb.begin(), vb.end());
            tmpb+=maxb;
            size_t vb_size = vb.size();
            size_t maxb_el_count = std::count(vb.begin(), vb.end(), maxb);
            if (vb_size==maxb_el_count) {
                ll maxa = *max_element(va.begin(), va.end());
                va.erase(va.begin()+ma.at(maxa));
                vb.erase(vb.begin()+ma.at(maxa));
            } else {
                va.erase(va.begin()+mb.at(maxb));
                vb.erase(vb.begin()+mb.at(maxb));
            }
        }
    }
    ll res = tmpa - tmpb;
    cout << res << '\n';
}
