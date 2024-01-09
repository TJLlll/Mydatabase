#ifndef __HashSep_H_
#define __HashSep_H_

#define ElementType int


typedef struct Data
{
    ElementType key;
    ElementType val;
}Data;

typedef struct HashNode
{
    Data* data;
    struct HashNode* Next;
}HashNode;

typedef struct HashList
{
    HashNode** HashTable;
    int tableSize;
}HashList;

/* 哈希表插入 */
int hashInset(HashList* hashList, ElementType val);

/* 哈希表查找 */
HashNode* find(ElementType val, HashList* hashList);

int hashListInit(HashList** hashList, int capcity);

#endif  // __HashSep_H_


