#include <cstdio>

int main() {
    int mem = 0;
    char input[1005];
    scanf("%s", input);
    for (int i = 0; input[i]; ++i) {
        if (input[i] == 'N') mem |= 1;
        if (input[i] == 'S') mem |= 2;
        if (input[i] == 'W') mem |= 4;
        if (input[i] == 'E') mem |= 8;
    }

    bool ok = true;
    if (mem & 3 && (mem & 3) != 3) ok = false;
    if (mem & 12 && (mem & 12) != 12) ok = false;

    if (ok) puts("Yes");
    else puts("No");
}

