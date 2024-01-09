#include <stdio.h>
#include "hashSep.h"

#define HASHSIZE    10

int main()
{
    HashList* hashList = NULL;
    hashListInit(&hashList, HASHSIZE);

    hashInset(hashList, 1);
    hashInset(hashList, 1);
    
}