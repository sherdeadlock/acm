#include <cstdio>
#include <cstring>

const int maxn = 101;

/**
 * return if `a` is less than `b`
 */
bool less(char s[], int len, int a, int b) {
    for (int i = 0; i < len; i++) {
        char cha = s[(a + i) % len];
        char chb = s[(b + i) % len];
        if (cha != chb) {
            return cha < chb;
        }
    }

    return false;
}

int main() {
    int T;
    char s[maxn];
    scanf("%d", &T);

    while (T--) {
        scanf("%s", s);
        int len = strlen(s);
        int ans = 0;
        for (int i = 1; i < len; i++) {
            if (less(s, len, i, ans)) {
                ans = i;
            }
        }

        for (int i = 0; i < len; i++) {
            putchar(s[(ans + i) % len]);
        }
        putchar('\n');
    }
    return 0;
}