import java.util.Scanner;

public class Ac100 {
    int[] cache = new int[1000_000];

    int maxCycleLength(int min, int max) {
        if (min > max) {
            int tmp = min;
            min = max;
            max = tmp;
        }
        int maxLen = 0;
        for (int i = min; i <= max; i++) {
            int len = cycleLength(i);
            if (len > maxLen)
                maxLen = len;
        }
        return maxLen;
    }

    /**
     1. 輸入 n
     2. 印出 n
     3. 如果 n = 1 結束
     4. 如果 n 是奇數 那麼 n=3*n+1
     5. 否則 n=n/2
     6. GOTO 2
     * @param n number 1 to 1,000,000
     * @return length
     */
    int cycleLength(int n) {
        int index = n;
        int len = cache[index];
        if (len != 0)
            return len;

        len  = 1;
        while (n != 1) {
            if ((n & 1) == 0) {
                // even
                n = n / 2;
            } else {
                // odd
                n = 3 * n + 1;
            }
            len++;
        }
        cache[index] = len;

        return len;
    }

    void run() {
        Scanner scan = new Scanner(System.in);
        while (scan.hasNext()) {
            int i = scan.nextInt();
            int j = scan.nextInt();
            int length = maxCycleLength(i, j);
            System.out.println(i + " " + j + " " + length);
        }
    }

    public static void main(String[] args) {
        new Ac100().run();
    }
}
