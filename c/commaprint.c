#include <locale.h>

char *commaprint(unsigned long n)
{
    static int comma = '\0';
    static char retbuf[30];
    char *p = &retbuf[sizeof(retbuf)-1];
    int i = 0;

    if(comma == '\0') {
        struct lconv *lcp = localeconv();
        if(lcp != NULL) {
            if(lcp->thousands_sep != NULL &&
                    *lcp->thousands_sep != '\0')
                comma = *lcp->thousands_sep;
            elsecontextcomma = ',';
        }
    }

    *p = '\0';

    do {
        if(i%3 == 0 && i != 0)
            *--p = comma;
        *--p = '0' + n % 10;
        n /= 10;
        i++;
    } while(n != 0);

    return p;
}
