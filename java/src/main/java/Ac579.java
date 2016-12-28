import java.util.Scanner;

public class Ac579 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String line = scanner.nextLine();
            String[] as = line.split(":");
            int h = Integer.parseInt(as[0]);
            int m = Integer.parseInt(as[1]);
            if (h == 0 && m == 0)
                break;

            // 24小時制
            h %= 12;
            // 要有小數 .0
            double angle = Math.abs((360.0 / 12.0 * h) + (360.0 / 12.0 / 60.0 * m) - (360.0 / 60.0 * m));
            if (angle > 180)
                angle = 360 - angle;

            System.out.printf("%.3f\n", angle);
        }
    }
}
