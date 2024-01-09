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
    INSERT_ERROR
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

/* key 与 val 的映射 , 可交给用户自定义 */
int keyGet(ElementType val)
{
    return val + 10;
}


int hash(int key, int tableSize)
{
    return key % tableSize;
}

/* 哈希表查找 */
HashNode* find(ElementType val, HashList* hashList)
{ 
    int key = keyGet(val);
    HashNode*travelNode = hashList->HashTable[hash(key, hashList->tableSize)]->Next;
    
    while(travelNode != NULL && travelNode->data->key != key)
    {
        travelNode = travelNode->Next;
    }

    return travelNode;
}

/* 哈希表插入 */
int hashInset(HashList* hashList, ElementType val)
{
    int key = keyGet(val);
   
    HashNode* travelNode = find(val, hashList);
    
    /* 哈希表中不存在该元素 */
    if(travelNode == NULL)
    {   
        travelNode = (HashNode*)malloc(sizeof(HashNode) * 1);
        travelNode->data = (Data*)malloc(sizeof(Data) * 1);
        travelNode->data->key = key;
        travelNode->data->val = val;
        travelNode->Next = hashList->HashTable[hash(key, hashList->tableSize)]->Next;
        hashList->HashTable[hash(key, hashList->tableSize)]->Next = travelNode;
    }
    else
    {
        printf("该值已存在!\n");
        return INSERT_ERROR;
    }
    
    printf("插入成功！\n");
    return ON_SUCCESS;
}