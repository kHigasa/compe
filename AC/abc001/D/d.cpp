#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

int value_round(int value, bool flag);

int main() {
    int N = 0;
    cin >> N;
    int* S = new int[N];
    int* E = new int[N];
    string line;
    for (int i=0;i<N;++i) {
        cin >> line;
        S[i] = atoi((line.substr(0, 4)).c_str());
        E[i] = atoi((line.substr(5, 4)).c_str());
        S[i] = value_round(S[i], true);
        E[i] = value_round(E[i], false);
    }

    int temp = 0;
    for (int i=0;i<N;++i) {
        for (int j=i;j<N;++j) {
            if (S[i] > S[j]) {
                temp = S[i];
                S[i] = S[j];
                S[j] = temp;
                temp = E[i];
                E[i] = E[j];
                E[j] = temp;
            }
        }
    }

    temp = E[0];
    cout << setfill('0') << setw(4) << S[0];
    for (int i=0;i<N-1;++i) {
        if (E[i] > temp) {
            temp = E[i];
        }

        if (temp < S[i+1]) {
            cout << "-" << setfill('0') << setw(4) << temp << endl;
            cout << setfill('0') << setw(4) << S[i+1];
        }
    }
    cout << "-" << setfill('0') << setw(4) << max(temp,E[N-1]) << endl;

    return 0;
}

int value_round(int value, bool flag) {
    if (value % 5 != 0) {
        if (flag == true) {
            value = value - value % 5;
        } else {
            value = value - value % 5 + 5;
        }
    }

    if (value % 100 == 60) {
        value = value - 60 + 100;
    }

    return value;
}
