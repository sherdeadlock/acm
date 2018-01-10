#include <cstdio>
#include <cstring>
#include <cctype>

const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msgs[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};

char revert(char ch) {
    if (isalpha(ch)) {
        return rev[ch - 'A'];
    } else {
        return rev[ch + 25 - '0'];
    }
}

int main() {
    char s[99];

    while (scanf("%s", s) == 1) {
        int p = 1, m = 1, len = strlen(s);
        for (int i = 0; i < (len + 1) / 2; i++) {
            if (s[i] != s[len - i - 1]) p = 0;
            if (revert(s[i]) != s[len - i - 1]) m = 0;
        }

        printf("%s -- is %s.\n\n", s, msgs[m * 2 + p]);
    }
    
    return 0;
}