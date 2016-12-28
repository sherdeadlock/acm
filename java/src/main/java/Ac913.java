import java.util.Scanner;

public class Ac913 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            // int overflow
            long n = scanner.nextLong();
            long row = n / 2;
//            int last = 1;
//            for (int i = 0; i < row; i++) {
//                last += ((3 + i * 2) * 2);
//            }
//            System.out.println(last * 3 - 6);
            System.out.println(6 * row * row + 12 * row - 3);
        }
    }
}
