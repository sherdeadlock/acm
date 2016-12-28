
import java.util.ArrayList;
import java.util.Scanner;

/**
 * 判斷點是否在矩形,圓形內
 */
public class Ac477 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Fig> rects = new ArrayList<>();
        while (scanner.hasNext()) {
            String line = scanner.nextLine();
            if (line.charAt(0) == '*')
                break;

            Fig fig = Fig.fromString(line);
            rects.add(fig);
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

    abstract static class Fig {
        abstract boolean contains(double x, double y);

        static Fig fromString(String s) {
            char ch = s.charAt(0);
            if (ch == 'r') {
                String[] as = s.split(" ");
                double x1 = Double.parseDouble(as[1]);
                double y2 = Double.parseDouble(as[2]);
                double x2 = Double.parseDouble(as[3]);
                double y1 = Double.parseDouble(as[4]);
                return new Rect(x1, y1, x2, y2);
            } else if (ch == 'c') {
                String[] as = s.split(" ");
                double cx = Double.parseDouble(as[1]);
                double cy = Double.parseDouble(as[2]);
                double r = Double.parseDouble(as[3]);
                return new Circle(cx, cy, r);
            } else
                throw new IllegalArgumentException(s);
        }
    }

    static class Circle extends Fig {
        double cx;
        double cy;
        double r;

        public Circle(double cx, double cy, double r) {
            this.cx = cx;
            this.cy = cy;
            this.r = r;
        }

        @Override
        boolean contains(double x, double y) {
            if (Math.abs(x - cx) > r || Math.abs(y - cy) > r)
                return false;

            double dist = Math.pow(x - cx, 2) + Math.pow(y - cy, 2);
            double r2 = Math.pow(r, 2);
            return dist < r2;
        }
    }

    static class Rect extends Fig {
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

        @Override
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
