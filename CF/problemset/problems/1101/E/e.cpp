/*****************************************
 * [WIP] This can't treat blank space well.
 ******************************************/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    char* sym = new char[N];
    int* H = new int[N];
    int* W = new int[N];
    string line = "00000";
    for (int i=0;i<N;++i) {
        cin >> line;
        sym[i] = line.at(0);
        H[i] = atoi((line.substr(2, 1)).c_str());
        W[i] = atoi((line.substr(4, 1)).c_str());
    }

    int max_length = 0;
    for (int i=0;i<N;++i) {
        switch (sym[i]) {
            case '+':
                max_length = max(max_length, max(H[i], W[i]));
                break;
            case '?':
                if (max_length <= max(H[i], W[i])) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
                break;
            default:
                break;
        }
    }

    return 0;
}
