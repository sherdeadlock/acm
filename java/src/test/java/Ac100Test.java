import org.junit.Test;

import static org.hamcrest.core.Is.is;
import static org.junit.Assert.assertThat;

public class Ac100Test {
    @Test
    public void test1() throws Exception {
        Ac100 ac = new Ac100();
        assertThat(ac.maxCycleLength(1, 10), is(20));
        assertThat(ac.maxCycleLength(10, 1), is(20));
        assertThat(ac.maxCycleLength(100, 200), is(125));
        assertThat(ac.maxCycleLength(201, 210), is(89));
        assertThat(ac.maxCycleLength(900, 1000), is(174));
    }
}
