#include "doubleCircleLinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 前置声明*/
static LinkNode* createLinkNode(ELEMENTTYPE val);
static int doubleLinkListApponitValPosGet(LinkList * list, ELEMENTTYPE val, int* pos, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

/* 创建节点 */
static LinkNode* createLinkNode(ELEMENTTYPE val)
{
    LinkNode* tmp = (LinkNode*)malloc(sizeof(LinkNode) * 1); 
    if(tmp == NULL)
    {
        return NULL;
    }
    memset(tmp, 0, sizeof(LinkNode) * 1);

    tmp->data = val;
    tmp->next = NULL;
    tmp->pre = NULL;

    return tmp;
}

/* 双链表初始化 */
int doubleLinkListInit(LinkList ** Dlist)
{
    int ret = 0; 
    LinkList * list = (LinkList*)malloc(sizeof(LinkList) * 1);
    if(list == NULL)
    {
        return NULL_PTR;
    }
    memset(list, 0, sizeof(LinkList) * 1);

    list->head = (LinkNode*)malloc(sizeof(LinkNode) * 1);
    list->head->data = 0;
    list->head->pre = NULL;
    list->head->next = NULL;
    list->len = 0;

    *Dlist = list;
    return ret;
}

/* 双循环链表指定位置插入元素 */
int doubleLinkListAppointPosInsert(LinkList* list, int pos, ELEMENTTYPE val)
{
    int ret = 0;
    if(list == NULL)
    {
        return NULL_PTR;
    }

    LinkNode* Node = createLinkNode(val);

    LinkNode* tmp = NULL;

    if(pos == 0 && list->len == 0)/* 当链表为空时头插 *//* ！！！！当节点数不为0时，头插会使插入后的节点1自身死循环 */
    {   
        list->head->next = Node;
        Node->next = Node;
        Node->pre = Node;
    }
    else if(pos == 0 && list->len != 0)/*  处理了非空时,头插插入元素的pre指向 *//* 容易疏忽 *//* 当链表中已有且仅有1个时， */
    {
        Node->next = list->head->next;
        Node->pre = list->head->next->pre;
        Node->next->pre = Node;
        Node->pre->next = Node;
        list->head->next = Node;
    }
    else if(list->len != 0 && pos == list->len)/* 尾插 */
    {
        tmp = list->head->next;
        Node->next = tmp;
        Node->pre = tmp->pre;
        tmp->pre->next = Node;
        tmp->pre = Node;
    }
    else/* 中间 */
    {

#if 0
        tmp = list->head->next;
        while(--pos)
        {
            tmp = tmp->next;
        }
#else
        tmp = list->head;
        while(pos--)
        {
            tmp = tmp->next;
        }
#endif
        Node->next = tmp->next;
        Node->pre = tmp;
        tmp->next->pre = Node;
        tmp->next = Node;
    }

    list->len++;
    return ret;
}

/* 头插 */
int doubleLinkListTopInsert(LinkList* list, ELEMENTTYPE val)
{
    return doubleLinkListAppointPosInsert(list, 0, val);
}

/* 尾插 */
int doubleLinkListTailInsert(LinkList* list, ELEMENTTYPE val)
{
    return doubleLinkListAppointPosInsert(list, list->len, val);
}

/* 头删 */
int doubleLinkListTopDel(LinkList* list)
{
    return doubleLinkListAppointPosDel(list, 1);
}

/* 尾删 */
int doubleLinkListTailDel(LinkList* list)
{
    return doubleLinkListAppointPosDel(list, list->len);
}

/* 毫无意义的获取链表长度函数 */
int doubleLinkListGetLength(LinkList* list)
{
    if (list == NULL)
    {
        return NULL_PTR;
    }
    return list->len;
}

/* 获取指定元素在链表中的位置 */
int doubleLinkListApponitValPosGet(LinkList * list, ELEMENTTYPE val, int* pos, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
{
    int ret = 0;
    if(list == NULL)
    {
        return NULL_PTR;
    }

    int tmp = 1;
    LinkNode* Node = list->head->next;
    int idx = list->len;
    while(idx--)
    {

        ret = compareFunc(val, Node->data);
        if(ret == 1)
        {
            *pos = tmp;
            return 0;
        }

        Node = Node->next;
        tmp++; 
    }

    return NOT_FIND;
}


#if 1
/* 链表删除指定位置元素 */
/* 通过pos来判断从头遍历还是从尾遍历 */
int doubleLinkListAppointPosDel(LinkList* list, int pos)
{
    int ret = 0;
    if(list == NULL)
    {
        return NULL_PTR;
    }
    printf("pos:%d,len:%d\n", pos, list->len);
    if(pos <= 0 || pos > list->len)
    {
        printf("Del Faild ! NOT Such Pos!!!\n");
        return NOT_FIND;
    }

    LinkNode* Node = list->head->next;
    int idx = (pos > (list->len - pos)) ? (list->len - pos) + 1 : pos;
    int flag = (pos > (list->len - pos)) ? 1 : 0;
    
    if (flag == 1)
    {
        printf("idx:%d\n", idx);
        printf("Tail Searching......\n");
        //tmp -= 1;
        while(idx--)
        {
            Node = Node->pre;/* Node->pre不会一直指向它自身吧？ */
        }
        printf("Searching Success!\n");
    }
    else
    {
        printf("idx:%d\n", idx);
        printf("ToplFinding......\n");
        if(idx = 1 && list->len > 1)/* ！！！当链表节点不只有一个时，头删需将head->next先后移，维护好头节点 */
        {
            LinkNode* tmpNode = list->head->next;
            list->head->next = tmpNode->next; 
        }
        idx -= 1;
        while(idx--)
        {
            Node = Node->next;
        }
        printf("Searching Success!\n");
    }
    
    
    /* 将目标节点从链表中取出 *//* 适用于只有一个元素时 *//* 非空时头删会导致head->next指空 */
    Node->pre->next = Node->next;
    Node->next->pre = Node->pre; 
    
    if(Node != NULL)
    {
        free(Node);
        Node = NULL;
    }
    
    list->len--;
    printf("DelSuccess!\n");
    return ret;
}
#else

int doubleLinkListAppointPosDel(LinkList* list, int pos)
{
    int ret = 0;
    if(list == NULL)
    {
        return NULL_PTR;
    }

    if(pos <= 0 && pos > list->len)
    {
        return NULL_PTR;
    }
    LinkNode* tmpNode = list->head->next;

    while (--pos)
    {
        tmpNode = tmpNode->next;
    }
    
    tmpNode->pre->next = tmpNode->next;
    tmpNode->next->pre = tmpNode->pre;
    if(tmpNode != NULL)
    {
        free(tmpNode);
    }

    list->len--;
    return ret;
}
#endif

/* 删除链表中指定元素 */
int doubleLinkListAppointvalDel(LinkList* list, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE va1, ELEMENTTYPE val2))
{
    int ret = 0;

    if(list == NULL)
    {
        return NULL_PTR;
    }
    int pos = 1;
    LinkNode* node = list->head->next;
    int idx = list->len;
    while(idx)
    {
        ret = compareFunc(val, node->data);
        node = node->next;
        if (ret == 1)
        {
            doubleLinkListAppointPosDel(list, pos);
            pos--;
            ret = 0;
        }
        pos++;
    }
    
    return ret;
}

/* 销毁链表 */
int doubleLinkListDestroy(LinkList* list)
{
    if(list == NULL)
    {
        return NULL_PTR;
    }
    while(list->len != 0)
    {
        doubleLinkListAppointPosDel(list, 0);
    }

    if(list->head != NULL)
    {
        free(list->head);
        list->head = NULL;
    }

    if(list != NULL)
    {
        free(list);
        list = NULL;
    }
    
    return 0;
}

/* 头序遍历 */
int doubleLinkListTopPrint(LinkList* list, int (*printFunc)(ELEMENTTYPE val))
{
    int ret = 0;
    if(list == NULL)
    {
        return NULL_PTR;
    }

    LinkNode* tmp = list->head->next;
    int index = list->len;

    while(index--)
    {
        printFunc(tmp->data);
        tmp = tmp->next;
    }
    return ret;
}

/* 尾序遍历 */
int doubleLinkListTailPrint(LinkList* list, int (*printFunc)(ELEMENTTYPE val))
{
    int ret = 0;
    if(list == NULL)
    {
        return NULL_PTR;
    }

    LinkNode* tmp = list->head->next;
    int idx = list->len;
    printf("idx:%d\n",idx);
    while(idx--)
    {
        tmp = tmp->pre;
        if(tmp == NULL)
        {
            printf("!!!\n");
        }
        printf("ok?\n");
        printFunc(tmp->data);
        
    }
    return ret;
}


/* 打印指定位置元素 */
int doubleLinkListAppointPosPrint(LinkList* list, int pos, int (*prinFunc)(ELEMENTTYPE val))
{
    int ret = 0;
    if(list == NULL)
    {
        return NULL_PTR;
    }

    if(pos <= 0 && pos > list->len)
    {
        return NOT_FIND;
    }

    LinkNode* tmp = NULL;
    tmp = list->head;

    while(pos--)
    {
        tmp = tmp->next;
    }
    prinFunc(tmp->data);

    return ret;
}
