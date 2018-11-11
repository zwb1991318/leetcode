import java.util.HashSet;

/**
 * Created by zwb on 2016/12/9.
 */
public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> resultHashSet = new HashSet<>();
        for (int i = 0; i < nums1.length; i++) {
            for (int j = 0; j < nums2.length; j++) {
                if (nums1[i] == nums2[j]) {
                    resultHashSet.add(nums1[i]);
                }
            }
        }

        Integer[] integerTemp = (Integer[]) resultHashSet.toArray();

        int[] resultInt = new int[resultHashSet.size()];
        for (int i = 0; i < integerTemp.length; i++) {
            resultInt[i] = integerTemp[i];
        }
        return resultInt;
    }
}
