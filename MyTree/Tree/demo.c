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
    demo liang = {18, "wonanshen"};
    demo gangge = {18, "gangshen"};
    doubleLinkListTopInsert(List, (void*)&Tao);
    doubleLinkListTopInsert(List, (void*)&liang);
    doubleLinkListAppointPosInsert(List, 0, (void*)&gangge);/* 当节点数不为0时，头插会死循环 */
    doubleLinkListTopPrint(List, printLinkList);
    //doubleLinkListTopDel(List);
    //doubleLinkListTopDel(List);
    //doubleLinkListTailDel(List);
    //doubleLinkListTailPrint(List,printLinkList);
    //doubleLinkListAppointPosDel(List, 2);
    //doubleLinkListTopPrint(List, printLinkList);
    //doubleLinkListTailPrint(List,printLinkList);
    printf("%d\n", List->len);
    return 0;
}