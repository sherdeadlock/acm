import java.util.Scanner;

public class Ac10018 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            long p = scanner.nextLong();
            long r = reverse(p);
            int count = 0;
            while (true) {
                count++;
                p = p + r;
                r = reverse(p);
                if (p == r)
                    break;
            }

            System.out.println(count + " " + p);
        }
    }

    static long reverse(long n) {
        long ret = 0;
        while (n != 0) {
            ret = ret * 10 + n % 10;
            n /= 10;
        }
        return ret;
    }
}
