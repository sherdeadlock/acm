#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;

bool is_end(int guess[], int size) {
    for (int i = 0; i < size; i++) {
        if (guess[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, count = 1;
    int ans[maxn], guess[maxn];
    
    while (scanf("%d", &n) == 1 && n) {
        printf("Game %d:\n", count++);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ans[i]);
        }

        while (true) {
            for (int i = 0; i < n; i++) {
                scanf("%d", &guess[i]);
            }

            if (is_end(guess, n)) {
                break;
            }

            int A = 0;
            for (int i = 0; i < n; i++) {
                if (ans[i] == guess[i]) {
                    A++;
                }
            }

            int B = 0;
            for (int d = 1; d <= 9; d++) {
                int counta = 0, countb = 0;
                for (int i = 0; i < n; i++) {
                    if (ans[i] == d) {
                        counta++;
                    }

                    if (guess[i] == d) {
                        countb++;
                    }
                }
                B += min(counta, countb);
            }
            B -= A;

            printf("    (%d,%d)\n", A, B);
        }
    }
    return 0;
}