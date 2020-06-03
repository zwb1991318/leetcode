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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHBUCKETLEN 256
#define OK 1
#define NOK 2

typedef struct HashEntry
{
    int key;
    int value;
    struct HashEntry *pNext;
} HashEntry;

typedef struct HashBucket
{
    HashEntry *Head;
} HashBucket;

typedef struct HashTable
{
    HashBucket bucket[HASHBUCKETLEN];
} HashTable;

HashTable * HashTableInit()
{

    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    if (table == NULL)
    {
        return NULL;
    }
    memset(table, 0, sizeof(HashTable));
    return table;
}

void HashTableInsert(HashTable *table, int num,int index)
{
    HashEntry *entry = NULL;
    unsigned int hash = 0;
    HashEntry **pInsert = NULL;
    HashEntry **pPreInsert = NULL;
    entry = (HashEntry *)malloc(sizeof(HashEntry));
    entry->key = num;
    entry->value = index;
    entry->pNext = NULL;

    hash = (unsigned int)num % HASHBUCKETLEN;
    pInsert = &table->bucket[hash].Head;

    if (*pInsert == NULL)
    {
        *pInsert = entry;
        return;
    }

    while (*pInsert != NULL && (*pInsert)->pNext != NULL)
    {
        *pInsert = (*pInsert)->pNext;
    }

    //find place to insert
    (*pInsert)->pNext = entry;
    return;
}

HashEntry * HashTableFind(HashTable *table, int num)
{
    unsigned char hash = 0;
    HashEntry *pHead = NULL;

    if (table == NULL)
    {
        return NULL;
    }

    hash = (unsigned int)num % HASHBUCKETLEN;

    pHead = table->bucket[hash].Head;

    while (pHead)
    {
        if (pHead->key == num)
        {
            return pHead;
        }
        else
        {
            pHead = pHead->pNext;
        }
    }

    return NULL;
}

// int *twoSum(int *nums, int numsSize, int target, int *returnSize)
// {
//     int *ret = (int *)malloc(2 * sizeof(int));
//     *returnSize = 2;
//     for (int i = 0; i < numsSize - 1; i++)
//     {
//         for (int j = i + 1; j < numsSize; j++)
//         {
//             if (nums[i] + nums[j] == target)
//             {
//                 ret[0] = i;
//                 ret[1] = j;
//                 return ret;
//             }
//         }
//     }

//     return ret;
// }

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *ret = (int *)malloc(2 * sizeof(int));
    HashTable *table = NULL;
    HashEntry *pHashEntry = NULL;

    *returnSize = 2;
    memset(ret,0,sizeof(int)*2);

    table = HashTableInit();

    for (int i = 0; i < numsSize; i++)
    {
        int goal = target - nums[i];
        pHashEntry = HashTableFind(table,goal);
        if(pHashEntry)
        {
            ret[0] = pHashEntry->value;
            ret[1] = i;
            return ret; 
        }
        else
        {
            //insert this num to hash
            HashTableInsert(table,nums[i],i);
        }
        
    }

    return ret;
}

// int main(int argc, char *argv[])
// {
// // [230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789]
// // 542
//     int nums[] ={230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789};
//     int *ret;
//     int returnSize;
//     ret = twoSum(nums,100,542,&returnSize);
//     printf("ahahhaha\n");
// }

// @lc code=end
