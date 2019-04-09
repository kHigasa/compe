#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char str[200005];
    scanf("%s", str);
    int n = strlen(str);
    int s_stack = 0, t_rest = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'S') {
            s_stack++;
        } else {
            if (s_stack > 0) s_stack--;
            else t_rest++;
        }
    }

    int ans = s_stack + t_rest;
    printf("%d\n", ans);
}

