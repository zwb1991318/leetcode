import org.junit.Assert;

import static org.junit.Assert.*;

/**
 * Created by zwb on 2017/3/29.
 */
public class MedianofTwoSortedArraysTest {

    @org.junit.Test
    public void MedianofTwoSortedArraysTestbythree() throws Exception {
        MedianofTwoSortedArrays test = new MedianofTwoSortedArrays();
        int[] num1 = {1};
        int[] num2 = {1};
        //assertEquals(2,test.lengthOfLongestSubstring("abba"));
        //((double)1,test.findMedianSortedArrays(num1,num2));
        Assert.assertEquals(1.0,test.findMedianSortedArrays(num1,num2),1.0);
    }

    @org.junit.Test
    public void MedianofTwoSortedArraysTestby2() throws Exception {
        MedianofTwoSortedArrays test = new MedianofTwoSortedArrays();
        int[] num1 = {1,1};
        int[] num2 = {1,1};
        //assertEquals(2,test.lengthOfLongestSubstring("abba"));
        //((double)1,test.findMedianSortedArrays(num1,num2));
        Assert.assertEquals(1.0,test.findMedianSortedArrays(num1,num2),1.0);
    }

    @org.junit.Test
    public void MedianofTwoSortedArraysTestby3() throws Exception {
        MedianofTwoSortedArrays test = new MedianofTwoSortedArrays();
        int[] num1 = {1,2};
        int[] num2 = {3,4};
        //assertEquals(2,test.lengthOfLongestSubstring("abba"));
        //((double)1,test.findMedianSortedArrays(num1,num2));
        Assert.assertEquals(2.5,test.findMedianSortedArrays(num1,num2),1.0);
    }
}