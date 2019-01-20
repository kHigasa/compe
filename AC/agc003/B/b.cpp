#include <iostream>

using namespace std;

int main() {
    long long N, A, res=0, tmp=0;
    cin >> N;
    for (int i=0;i<N;++i) {
        cin >> A;
        if(A!=0) {
            tmp+=A;
        }
        else {
            res+=abs(tmp/2);
            tmp=0;
        }
    }
    res+=abs(tmp/2);
    cout << res << "\n";
    return 0;
}
