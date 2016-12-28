import java.io.IOException;
import java.util.HashMap;

public class Ac10082 {

    static void gen() {
        HashMap<Character, Character> map = new HashMap<>();
        map.put('1', '`');
        map.put('2', '1');
        map.put('3', '2');
        map.put('4', '3');
        map.put('5', '4');
        map.put('6', '5');
        map.put('7', '6');
        map.put('8', '7');
        map.put('9', '8');
        map.put('0', '9');
        map.put('-', '0');
        map.put('=', '-');

        map.put('W', 'Q');
        map.put('E', 'W');
        map.put('R', 'E');
        map.put('T', 'R');
        map.put('Y', 'T');
        map.put('U', 'Y');
        map.put('I', 'U');
        map.put('O', 'I');
        map.put('P', 'O');
        map.put('[', 'P');
        map.put(']', '[');
        map.put('\\', ']');

        map.put('S', 'A');
        map.put('D', 'S');
        map.put('F', 'D');
        map.put('G', 'F');
        map.put('H', 'G');
        map.put('J', 'H');
        map.put('K', 'J');
        map.put('L', 'K');
        map.put(';', 'L');
        map.put('\'', ';');

        map.put('X', 'Z');
        map.put('C', 'X');
        map.put('V', 'C');
        map.put('B', 'V');
        map.put('N', 'B');
        map.put('M', 'N');
        map.put(',', 'M');
        map.put('.', ',');
        map.put('/', '.');

        System.out.print("char[] table = new char[] {");
        for (int i = 0; i < 256; i++) {
            Character ch = map.get((char) i);
            if (i != 0) {
                System.out.print(", ");
            }
            if (ch == null)
                System.out.print("0");
            else
                System.out.print("'" + ch + "'");
        }
        System.out.print("};");
        System.out.println();
    }

    static char[] table = new char[] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ';', 0, 0, 0, 0, 'M', '0', ',', '.', '9', '`', '1', '2', '3', '4', '5', '6', '7', '8', 0, 'L', 0, '-', 0, 0, 0, 0, 'V', 'X', 'S', 'W', 'D', 'F', 'G', 'U', 'H', 'J', 'K', 'N', 'B', 'I', 'O', 0, 'E', 'A', 'R', 'Y', 'C', 'Q', 'Z', 'T', 0, 'P', ']', '[', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    static void run() throws IOException {
        int ch;
        while ((ch = System.in.read()) != -1) {
            if (ch == ' ' || ch == '\n') {
                System.out.write(ch);
            } else {
                System.out.write(table[ch]);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        //gen();
        run();
    }
}
