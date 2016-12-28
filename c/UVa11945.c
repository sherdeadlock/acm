#include <stdio.h>

char retbuf[100];

char* commaprint(unsigned long n) {
    char *p = &retbuf[sizeof(retbuf)-1];
    int i = 0;

    *p = '\0';

    for (i = 0; i < 2; i++) {
        *--p = '0' + n % 10;
        n /= 10;
    }
    *--p = '.';

    i = 0;
    do {
        if (i%3 == 0 && i != 0)
            *--p = ',';
        *--p = '0' + n % 10;
        n /= 10;
        i++;
    } while (n != 0);

    return p;
}

int main(int argc, char *argv[]) {
    int i, j, count;
    unsigned long sum, avg, a, b;
    scanf("%d", &count);
    for (i = 1; i <= count; i++) {
        sum = 0;
        for (j = 0; j < 12; j++) {
            scanf("%lu.%lu", &a, &b);
            sum += (a*100 + b);
        }
        avg = sum/12 + (sum%12 >= 6); /* 四捨五入 round */
        printf("%d $%s\n", i, commaprint(avg));
    }
    return 0;
}
