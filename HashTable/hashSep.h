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


#endif  // __HashSep_H_


