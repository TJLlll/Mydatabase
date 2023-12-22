#ifndef __DOUBLE_CIRCLE_LINKLIST_H_
#define __DOUBLE_CIRCLE_LINKLIST_H_


#define ELEMENTTYPE void*

/* 双链表节点 */
typedef struct LinkNode
{
    ELEMENTTYPE data;
    struct LinkNode * pre;
    struct LinkNode * next;

}LinkNode;

/* 双链表 */
typedef struct LinkList
{
    LinkNode * head;
    int len;
}LinkList;

/* 双链表初始化 */
int doubleLinkListInit(LinkList** Dlist);

/* 双循环链表指定位置插入元素 */
int doubleLinkListAppointPosInsert(LinkList* list, int pos, ELEMENTTYPE val);

/* 头插 */
int doubleLinkListTopInsert(LinkList* list, ELEMENTTYPE val);

/* 尾插 */
int doubleLinkListTailInsert(LinkList* list, ELEMENTTYPE val);

/* 头删 */
int doubleLinkListTopDel(LinkList* list);

/* 尾删 */
int doubleLinkListTailDel(LinkList* list);

/* 毫无意义的获取链表长度函数 */
int doubleLinkListGetLength(LinkList* list);

/* 链表删除指定位置元素 */
/* 通过pos来判断从头遍历还是从尾遍历 */
int doubleLinkListAppointPosDel(LinkList* list, int pos);

/* 删除链表中指定元素 */
int doubleLinkListAppointvalDel(LinkList* list, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE va1, ELEMENTTYPE val2));

/* 销毁链表 */
int doubleLinkListDestroy(LinkList* list);

/* 头序遍历 */
int doubleLinkListTopPrint(LinkList* list, int (*printFunc)(ELEMENTTYPE val));

/* 尾序遍历 */
int doubleLinkListTailPrint(LinkList* list, int (*printFunc)(ELEMENTTYPE val));

/* 打印指定位置元素 */
int doubleLinkListAppointPosPrint(LinkList* list, int pos, int (*prinFunc)(ELEMENTTYPE val));

#endif