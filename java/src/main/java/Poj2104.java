import java.util.Arrays;
import java.util.Scanner;

public class Poj2104 {
    static final int MAX = 100010;
    int[][] tree = new int[30][MAX];
    int[] sorted = new int[MAX];
    int[][] toLeft = new int[30][MAX];

    /**
     *
     * @param l left index
     * @param r right index
     * @param dep tree depth
     */
    void build(int l, int r,int dep) {
        if (l == r) {
            return;
        }

        int mid = (l + r) >> 1;
        int leftCount = mid - l + 1;
        int[] row = tree[dep];
        int[] rowNext = tree[dep + 1];

        int lpos = l;
        int rpos = mid + 1;
        for (int i = l; i <= r; i++) {
            int cur = row[i];
            if (cur < sorted[mid]) {
                rowNext[lpos++] = cur;
                leftCount--;
            } else if (cur == sorted[mid] && leftCount > 0) {
                rowNext[lpos++] = cur;
                leftCount--;
            } else {
                rowNext[rpos++] = cur;
            }

            // 紀錄被歸類left的個數
            toLeft[dep][i] = toLeft[dep][l - 1] + lpos - l;
        }

        build(l, mid, dep + 1);
        build(mid + 1, r, dep + 1);
    }

    /**
     * L <= l && r <= R
     * @param L min index
     * @param R max index
     * @param l left index
     * @param r right index
     * @param dep depth
     * @param k k-th number
     */
    int query(int L, int R, int l, int r, int dep, int k) {
        if (l == r)
            return tree[dep][l];
        //System.out.println(l  + " " + r);
        int mid = (L + R) >> 1;
        int[] row = toLeft[dep];
        int count = row[r] - row[l - 1];
        if (count >= k) {
            // left
            int newl = L - row[L - 1] + row[l - 1];
            int newr = newl + count - 1;
            return query(L, mid, newl, newr, dep + 1, k);
        } else {
            // right
            int newr = r + row[R] - row[r];
            int newl = newr - (r - l - count);
            return query(mid + 1, R, newl, newr, dep + 1, k - count);
        }
    }

    void showTree() {
        showTree(tree);
        System.out.println();
        showTree(toLeft);
    }
    void showTree(int[][] arr) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 10; j++) {
                System.out.print(arr[i][j]);
                System.out.print(" ");
            }
            System.out.println();
        }
    }

    void run() {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int n = scanner.nextInt();// array size 1 <= n <= 100000
            int m = scanner.nextInt();// problems 1 <= m <= 5000

            // array
            for (int i = 1; i <= n; i++) {
                int read = scanner.nextInt();
                tree[0][i] = read;
                sorted[i] = read;
            }
            Arrays.sort(sorted, 1, n + 1);
            build(1, n, 0);

            //showTree();

            // problems
            for (int i = 0; i < m; i++) {
                int l = scanner.nextInt();
                int r = scanner.nextInt();
                int k = scanner.nextInt();
                System.out.println(query(1, n, l, r, 0, k));
            }
        }
    }

    public static void main(String[] args) {
        new Poj2104().run();
    }
}
