/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * 最普通的暴力写法
 * 时间复杂度 O(n*n)
 * 空间复杂度O(1)
 */
#if 0
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
#endif 

/**
 * 一次hash的方法
 */
# include <string.h>

typedef struct Node
{
    int key;
    int value;
    struct Node *next;
}node;

typedef struct HashTab
{
    int keyNum;
    struct Node *head;
}hashTab;

int numTo2N(int num)
{
    int i = 1 , tmp = num;
    while(num >>= 1){
        i <<= 1;
    }
    
    return (i<tmp) ? i<<1 : i;
}

int* twoSum(int* nums, int numsSize, int target) {
    static int targetArr[2] = {0};
    int index = 0;
    int hashLength = numTo2N(numsSize);
    hashTab * pHashTab = (hashTab * )malloc(sizeof(hashTab) * hashLength);

    if(pHashTab = 0)
    {
        return targetArr;
    }

    memset(pHashTab , 0 , sizeof(hashTab) * hashLength);
    
}