import junit.framework.Assert;

import static org.junit.Assert.*;

/**
 * Created by zwb on 2016/12/25.
 */
public class LongestNoReaptingSubstringTest {

    @org.junit.Test
    public void testLengthOfLongestSubstring() throws Exception {
        LongestNoReaptingSubstring test = new LongestNoReaptingSubstring();
        assertEquals(2,test.lengthOfLongestSubstring("abba"));
    }
}