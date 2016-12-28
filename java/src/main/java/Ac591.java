import java.util.*;

public class Ac591 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int seq = 1;
        while (scanner.hasNext()) {
            int n = scanner.nextInt();
            if (n == 0)
                break;

            ArrayList<Integer> lst = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                lst.add(scanner.nextInt());
            }
            int sum = sum(lst);
            int h = sum / n;
            int count = 0;
            for (Integer num : lst) {
                int diff = num - h;
                if (diff > 0)
                    count += diff;
            }

            System.out.println("Set #" + seq);
            System.out.println("The minimum number of moves is " + count + ".");
            System.out.println();//最後一個也要有空行
            seq++;
        }
    }

    static int sum(ArrayList<Integer> lst) {
        int sum = 0;
        for (Integer n : lst) {
            sum += n;
        }
        return sum;
    }
}
