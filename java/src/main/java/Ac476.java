import java.util.ArrayList;
import java.util.Scanner;

/**
 * 兩個點表示一個矩形,判斷點是否落在矩形裡面.
 */
public class Ac476 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Rect> rects = new ArrayList<>();
        while (scanner.hasNext()) {
            String line = scanner.nextLine();
            if (line.charAt(0) == '*')
                break;

            String[] as = line.split(" ");
            double x1 = Double.parseDouble(as[1]);
            double y2 = Double.parseDouble(as[2]);
            double x2 = Double.parseDouble(as[3]);
            double y1 = Double.parseDouble(as[4]);

            Rect rect = new Rect(x1, y1, x2, y2);
            rects.add(rect);
        }

        int count = 0;
        while (scanner.hasNext()) {
            double x = scanner.nextDouble();
            double y = scanner.nextDouble();
            // end
            if (x == 9999.9 && y == 9999.9)
                break;

            count++;

            int fig = -1;
            for (int i = 0; i < rects.size(); i++) {
                if (rects.get(i).contains(x, y)) {
                    fig = i + 1;
                    System.out.println("Point " + count + " is contained in figure " + fig);
                }
            }

            if (fig == -1)
                System.out.println("Point " + count + " is not contained in any figure");
        }
    }

    static class Rect {
        double x1;
        double y1;
        double x2;
        double y2;

        public Rect(double x1, double y1, double x2, double y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }

        boolean contains(double x, double y) {
            return x > x1 && x < x2 && y > y1 && y < y2;
        }

        @Override
        public String toString() {
            return "Rect{" +
                    "x1=" + x1 +
                    ", y1=" + y1 +
                    ", x2=" + x2 +
                    ", y2=" + y2 +
                    '}';
        }
    }
}
