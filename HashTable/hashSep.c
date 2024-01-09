#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashSep.h"

enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};


int hashListInit(HashList** hashList, int capcity)
{
    int ret = 0;

    if(hashList == NULL)
    {
        return NULL_PTR;
    }
    HashList* tmpHashList = (HashList*)malloc(sizeof(HashList) * 1);
    if(tmpHashList == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(tmpHashList, 0, sizeof(HashList));
    
    /* 初始化哈希表数组 */
    tmpHashList->tableSize = capcity;
    tmpHashList->HashTable = (HashNode**)malloc(sizeof(HashNode*) * (capcity));
    if(tmpHashList->HashTable == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(tmpHashList->HashTable, 0, sizeof(HashNode*) * capcity);

    /* 初始化哈希表数组中每一个指针 */
    for(int idx = 0; idx < capcity; idx++)
    {
        tmpHashList->HashTable[idx] = (HashNode*)malloc(sizeof(HashNode) * 1);
        if(tmpHashList->HashTable[idx] == NULL)
        {
            return MALLOC_ERROR;
        }
        memset(tmpHashList->HashTable[idx], 0, sizeof(HashNode) *1);

        tmpHashList->HashTable[idx]->data = NULL;
        tmpHashList->HashTable[idx]->Next = NULL;
    }

    *hashList = tmpHashList;
    return ret;

}