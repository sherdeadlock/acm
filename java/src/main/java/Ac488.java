import java.util.HashMap;
import java.util.Scanner;

public class Ac488 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashMap<Integer, String> cache = new HashMap<>();
        int count = scanner.nextInt();
        for (int i = 0; i < count; i++) {
            int a = scanner.nextInt();
            int f = scanner.nextInt();

            if (i != 0)
                System.out.println();

            String wave = cache.get(a);
            if (wave == null) {
                wave = wave(a);
                cache.put(a, wave);
            }

            for (int j = 0; j < f; j++) {
                if (j != 0)
                    System.out.println();
                System.out.print(wave);
            }
        }
    }

    static String wave(int a) {
        StringBuilder sb = new StringBuilder(a*a);
        for (int i = 1; i <= a; i++) {
            repeat(i, sb);
            sb.append('\n');
        }
        for (int i = a - 1; i > 0 ; i--) {
            repeat(i, sb);
            sb.append('\n');
        }
        return sb.toString();
    }

    static void repeat(int n, StringBuilder sb) {
        for (int i = 0; i < n; i++) {
            sb.append(n);
        }
    }
}
