#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str;
    vector<int> coord(2,0);
    cin >> str;
    for (int i=0;i<str.size();++i) {
        switch(str[i]) {
            case 'N':
                coord[1]+=1;
                break;
            case 'W':
                coord[0]-=1;
                break;
            case 'S':
                coord[1]-=1;
                break;
            case 'E':
                coord[0]+=1;
                break;
            default:
                break;
        }
    }
    if (coord[0]==0 && coord[1]==0) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}
