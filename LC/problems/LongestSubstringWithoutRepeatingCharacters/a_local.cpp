#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int res=0;
    vector<int> m(128,0);
    string s;
    cin >> s;
    for (int i=0,j=0;j<s.size();++j) {
        if (m[s[j]]++==0) {
            res=max(res,j-i+1);
        } else {
            while (i<j && m[s[j]]>1) {
                m[s[i]]--;
                i++;
            }
        }
    }
    cout << res << endl;
    return 0;
};
