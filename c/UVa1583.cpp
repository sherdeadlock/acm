#include <cstdio>
#include <cstring>

const int maxn = 100001;

int main() {
    int ans[maxn];
    memset(ans, 0, sizeof(ans));

    for (int i = 1; i < maxn; i++) {
        int n = i;
        int y = i;
        do {
            y += n % 10;
            n /= 10;
        } while (n > 0);

        if (ans[y] == 0 && y < maxn) {
            ans[y] = i;
        }
    }

    int T, n;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }

    return 0;
}