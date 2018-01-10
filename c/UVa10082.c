#include <stdio.h>

int main() {
    const char keyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    int i, c;
    while ((c = getchar()) != EOF) {
        for (i = 1; keyboard[i] && keyboard[i] != c; i++);
        if (keyboard[i]) putchar(keyboard[i - 1]);
        else putchar(c);
    }

    return 0;
}