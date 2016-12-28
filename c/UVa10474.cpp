#include <cstdio>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[]) {
    int T, Q, t, i, count=0;
    int marbles[10001];
    while (scanf("%d %d", &T, &Q) == 2 && T) {
        printf("CASE# %d:\n", ++count);
        for (i = 0; i < T; i++) {
            scanf("%d", &marbles[i]);
        }

        sort(marbles, marbles+T);

        while (Q--) {
            scanf("%d", &t);
            /* 同值時, 取最小index */
            int index = lower_bound(marbles, marbles+T, t) - marbles;
            if (index < T && marbles[index] == t)
                printf("%d found at %d\n", t, index+1);
            else
                printf("%d not found\n", t);
        }
    }
    return 0;
}
