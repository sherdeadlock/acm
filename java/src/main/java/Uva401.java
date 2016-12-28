import java.util.Scanner;

public class Uva401 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String table = "1SE Z  8        A   3  HIL JM O   2TUVWXY5";
        String[] ps = new String[]{
                " -- is not a palindrome.",
                " -- is a regular palindrome.",
                " -- is a mirrored string.",
                " -- is a mirrored palindrome."
        };
        while (scanner.hasNext()) {
            String line = scanner.nextLine().trim();
            int mid = (line.length() + 1) >> 1;

            int p = 1;
            int m = 1;
            for (int i = 0, j = line.length() - 1; i < mid; i++, j--) {
                char a = line.charAt(i);
                char b = line.charAt(j);
                char ar = table.charAt(a - 49);
                //char br = table.charAt(b - 49);

                // palindrome
                if (a != b)
                    p = 0;

                // mirrored
                if (ar != b)
                    m = 0;

                if (p == 0 && m == 0)
                    break;
            }

            System.out.println(line + ps[2 * m + p]);
            System.out.println();
        }
    }
}
