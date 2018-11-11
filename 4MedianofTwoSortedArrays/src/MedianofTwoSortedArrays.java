import java.util.ArrayList;

/**
 * Created by zwb on 2017/3/29.
 */
public class MedianofTwoSortedArrays {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int i = 0;
        int j = 0;
        boolean isDouble;
        double lastNum = 0;
        double thisNum = 0;

        int middle = (nums1.length + nums2.length) / 2 + 1;
        isDouble = (nums1.length + nums2.length) % 2 == 0 ? true : false;

        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                lastNum = thisNum;
                thisNum = nums1[i];
                i++;
            } else if (nums1[i] > nums2[j]) {
                lastNum = thisNum;
                thisNum = nums2[j];
                j++;
            } else {
                lastNum = thisNum;
                thisNum = nums1[i];
                i++;
                if (i + j == middle) {
                    return returnMid(isDouble, lastNum, thisNum);
                }
                lastNum = thisNum;
                thisNum = nums2[j];
                j++;
            }

            if (i + j  == middle) {
                return returnMid(isDouble, lastNum, thisNum);
            }
        }
        while (i < nums1.length) {
            lastNum = thisNum;
            thisNum = nums1[i];
            i++;
            if (i + nums2.length == middle) {
                return returnMid(isDouble, lastNum, thisNum);
            }
        }
        while (j < nums2.length) {
            lastNum = thisNum;
            thisNum = nums2[j];
            j++;
            if (j + nums1.length == middle) {
                return returnMid(isDouble, lastNum, thisNum);
            }
        }

        return 0;

    }

    private double returnMid(boolean isDouble, double lastNum, double thisNum) {
        if (isDouble) {
            return (lastNum+thisNum)/2;
        } else {
            return thisNum;
        }
    }
}
