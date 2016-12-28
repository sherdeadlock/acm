#include <stdio.h>
#include <stdlib.h>


int int_cmp(const void* a, const void* b) {
    const int arg1 = *(const int*)a;
    const int arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

/* 
 * lower_bound 最快, bsearch 要往回找反而慢
 */
int find(int *a, int count, int q) {
    int *p = a;
    while (count--) {
        int x = *p++;
        if (x > q)
            break;

        if (x == q)
            return p - a - 1;
    }

    return -1;
}

int main(int argc, char* argv[]) {
    int T, Q, t, i, count=0;
    int marbles[10001];
    while (scanf("%d%d", &T, &Q) == 2 && T) {
        printf("CASE# %d:\n", ++count);
        for (i = 0; i < T; i++) {
            scanf("%d", &marbles[i]);
        }

        qsort(marbles, T, sizeof(int), int_cmp);
        while (Q--) {
            scanf("%d", &t);
            int index = find(marbles, T, t);
            if (index >= 0) {
                printf("%d found at %d\n", t, index+1);
            } else {
                printf("%d not found\n", t);
            }
        }
    }
    return 0;
}
