import java.util.Scanner;

public class Ac10035 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            if (x == 0 && y == 0)
                break;

            int carry = 0;
            int count = 0;
            while (x != 0 || y != 0) {
                int a = x % 10;
                int b = y % 10;
                if (a + b + carry >= 10) {
                    carry = 1;
                    count++;
                } else {
                    carry = 0;
                }

                x /= 10;
                y /= 10;
            }

            switch (count) {
                case 0:
                    System.out.println("No carry operation.");
                    break;
                case 1:
                    System.out.println("1 carry operation.");
                    break;
                default:
                    System.out.println(count + " carry operations.");
                    break;
            }
        }
    }
}
