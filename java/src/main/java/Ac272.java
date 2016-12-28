import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Ac272 {
    int count = 0;
    PrintWriter writer;

    public Ac272(OutputStream out) {
        this.writer = new PrintWriter(out);
    }

    void write(String str) {
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch == '"') {
                count++;
                if ((count & 1) == 0) {
                    // end
                    writer.append("''");
                } else {
                    // start
                    writer.append("``");
                }
            } else {
                writer.append(ch);
            }
        }

        writer.write("\n");
        writer.flush();
    }

    public void run() {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            // next() 會錯,應該時印出 EOF? 還是少一個\n
            String line = scanner.nextLine();
            write(line);
        }
    }

    public static void main(String[] args) {
        new Ac272(System.out).run();
    }
}
