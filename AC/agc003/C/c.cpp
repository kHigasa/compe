#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N,A,count=0,tmp;
    vector<long long> v_even,v_odd,ans(N);
    cin >> N;
    for (int i=0;i<N;++i) {
        cin >> A;
        if(i%2==0) {
            v_even.push_back(A);
        }
        else {
            v_odd.push_back(A);
        }
    }
    sort(v_even.begin(),v_even.end());
    sort(v_odd.begin(),v_odd.end());
    for (int i=0,j=0,k=0;i<N;++i) {
        if(i%2==0) {
            ans[i]=v_even[j];
            ++j;
        }
        else {
            ans[i]=v_odd[k];
            ++k;
        }
    }
    for (int i=0;i<N-1;++i) {
        if(ans[i]>ans[i+1]) {
            tmp=ans[i];
            ans[i]=ans[i+1];
            ans[i+1]=tmp;
            ++count;
        }
    }
    cout << count << "\n";
    return 0;
}
