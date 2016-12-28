import java.io.IOException;

public class Ac458 {
    public static void main(String[] args) {
        int ch;
        try {
            while ((ch = System.in.read()) != -1) {
                if (ch != '\n') {
                    ch = ch - 7;
                }
                System.out.write(ch);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
