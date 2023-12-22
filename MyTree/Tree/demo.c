#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "doubleCircleLinkList.h"
int compareData(void* arg1, void* arg2)
{
    int num1 = *(int *)arg1;
    int num2 = *(int *)arg2;

    return num1 == num2 ? 1 : 0;
}

typedef struct demo
{
    int age;
    char str[10];
    
}demo;


int printLinkList(void* val)
{
    printf("demo.age:%d, demo.str:%s\n", ((demo*)val)->age, ((demo*)val)->str);
}


int main()
{
    LinkList * List = NULL;
    doubleLinkListInit(&List);
    demo Tao = {18, "wanrengmi"};
    double1LinkListTopInsert(List, (void*)&Tao);
    doubleLinkListTopPrint(List, printLinkList);
    return 0;
}