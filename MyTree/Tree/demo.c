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

/* 尾序遍历依旧有问题 */
/* 指定位置删也很抽象 */
int main()
{
    LinkList * List = NULL;
    doubleLinkListInit(&List);
    demo Tao = {18, "wanrengmi"};
    demo liang = {18, "wonanshen"};
    demo gangge = {18, "gangshen"};
    doubleLinkListTopInsert(List, (void*)&Tao);
    doubleLinkListTopInsert(List, (void*)&Tao);
    doubleLinkListTopInsert(List, (void*)&liang);
    doubleLinkListTopInsert(List, (void*)&liang);
    doubleLinkListAppointPosInsert(List, 0, (void*)&gangge);
    //doubleLinkListTopPrint(List, printLinkList);
    //doubleLinkListAppointPosPrint(List, 1, printLinkList);
    //doubleLinkListTopDel(List);
    //doubleLinkListTopDel(List);
    //doubleLinkListTailDel(List);
    //doubleLinkListTailDel(List);
    //doubleLinkListTailPrint(List,printLinkList);
    //doubleLinkListAppointPosDel(List, 1);
    //doubleLinkListAppointPosDel(List, 1);/* 尾删依旧存在缺陷 */
    //doubleLinkListAppointPosDel(List, 4);
    doubleLinkListTopPrint(List, printLinkList);
    //doubleLinkListTailPrint(List, printLinkList);/* 尾序遍历不能和尾删同时出现 */
    printf("List->len:%d\n", List->len);
    return 0;
}