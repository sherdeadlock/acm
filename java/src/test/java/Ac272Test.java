import org.junit.Before;
import org.junit.Test;

import java.io.ByteArrayOutputStream;

import static org.hamcrest.core.Is.is;
import static org.junit.Assert.assertThat;

public class Ac272Test {
    ByteArrayOutputStream out;
    Ac272 ac;

    @Before
    public void setup() {
        out = new ByteArrayOutputStream();
        ac = new Ac272(out);
    }

    @Test
    public void test1() throws Exception {
        ac.write("\"To be or not to be,\" quoth the Bard, \"that\n" +
                "is the question\".\n" +
                "The programming contestant replied: \"I must disagree.\n" +
                "To `C' or not to `C', that is The Question!\"");

        String expect = "``To be or not to be,'' quoth the Bard, ``that\n" +
                "is the question''.\n" +
                "The programming contestant replied: ``I must disagree.\n" +
                "To `C' or not to `C', that is The Question!''\n";

        assertThat(out.toString(), is(expect));
    }

//    @Test
//    public void test2() throws Exception {
//        ac.write("\"To be or not to be,\" quoth the Bard, \"that\n" +
//                "is the question\".\n" +
//                "The programming contestant replied: \"I must disagree.\n" +
//                "To `C' or not to `C', that is The Question!\"xxxxxxx\"xxxxxxxx");
//
//        String expect = "``To be or not to be,'' quoth the Bard, ``that\n" +
//                "is the question''.\n" +
//                "The programming contestant replied: ``I must disagree.\n" +
//                "To `C' or not to `C', that is The Question!''xxxxxxx\"xxxxxxxx";
//
//        String actual = out.toString();
//        assertThat(actual, is(expect));
//
//    }
}
