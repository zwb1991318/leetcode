import org.junit.Assert;

import static org.junit.Assert.*;

/**
 * Created by zwb on 2017/4/3.
 */
public class ReverseIntegerTest {
    @org.junit.Test
    public void reverseOnePositiveNum() throws Exception {
        ReverseInteger test = new ReverseInteger();
        Assert.assertEquals(3,test.reverse(3));
    }

    @org.junit.Test
    public void reverseOneNegativeNum() throws Exception {
        ReverseInteger test = new ReverseInteger();
        Assert.assertEquals(-3,test.reverse(-3));
    }

    @org.junit.Test
    public void reverseSomePositiveNum() throws Exception {
        ReverseInteger test = new ReverseInteger();
        Assert.assertEquals(123,test.reverse(321));
    }

    @org.junit.Test
    public void reverseSomeNegativeNum() throws Exception {
        ReverseInteger test = new ReverseInteger();
        Assert.assertEquals(-123,test.reverse(-321));
    }

    @org.junit.Test
    public void reverse9646324351() throws Exception {
        ReverseInteger test = new ReverseInteger();
        Assert.assertEquals(0,test.reverse(1534236469));
    }
}