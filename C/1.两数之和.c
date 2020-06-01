/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (48.56%)
 * Likes:    8318
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.2M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define HASHBUCKETLEN 16
#define NULL 0

typedef struct HashEntry
{
    int key;
    int value;
    int * pNext;
} HashEntry;

typedef struct HashBucket
{
    HashEntry *Head;
} HashBucket;

typedef struct HashTable
{
    HashBucket bucket[HASHBUCKETLEN];
} HashTable;

void HashTableInit(HashTable *table)
{
    if (table == NULL)
    {
        return;
    }

    table = (HashTable *)malloc(sizeof(HashTable));
    memset(table, 0, sizeof(HashTable));
}

void HashTableInsert(HashTable *table,int num)
{
    HashEntry *entry = NULL;
    unsigned int hash = 0;
    HashEntry *pInsert = NULL;
    HashEntry *pPreInsert = NULL;
    entry = (HashEntry *)malloc(sizeof(HashEntry));
    entry->key = num;
    entry->value = num;
    entry->pNext = NULL;

    hash = num % HASHBUCKETLEN;
    pInsert = &table->bucket[hash].Head;

    if(pInsert == NULL)
    {
        pInsert = entry;
        return;
    }

    while (pInsert != NULL &&pInsert->pNext != NULL)
    {
        pInsert = pInsert->pNext;
    }
    
    //find place to insert
    pInsert = entry;
    return;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *ret = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }

    return ret;
}

// @lc code=end
