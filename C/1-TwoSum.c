/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    static int targetArr[2] = {0};
    for(int index = 0 ; index < numsSize -1 ; index ++)
    {
        for(int lastIndex = index + 1; lastIndex < numsSize ; lastIndex++)
        {
            if(nums[lastIndex] == target - nums[index])
            {
                targetArr[0] = index;
                targetArr[1] = lastIndex;
                break;
            }
        }      
    }
    return targetArr;
}