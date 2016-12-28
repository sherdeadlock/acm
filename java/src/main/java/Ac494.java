import java.io.IOException;

public class Ac494 {
    public static void main(String[] args) throws IOException {
        int[] table = new int[256];
        for (int i = 'A'; i < 'Z'; i++) {
            table[i] = 1;
        }
        for (int i = 'a'; i < 'z'; i++) {
            table[i] = 1;
        }

        int ch;
        int count = 0;
        boolean word = false;
        while ((ch = System.in.read()) != -1) {
            if (ch == '\n') {
                if (word)
                    count++;

                word = false;
                System.out.println(count);
                count = 0;
            }

            if (table[ch] == 1) {
                if (!word)
                    word = true;
            } else {
                if (word) {
                    word = false;
                    count++;
                }
            }
        }
    }
}
