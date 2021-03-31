#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
*L = (LinkedList)malloc(sizeof(LNode));//给空间 
        if(!(*L)) return ERROR;//判断 
        (*L)->next =NULL;//与Creat()函数调用时的相关性 
        return SUCCESS;

}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L)  {
LinkedList p;
while(*L){
p = (*L)->next;//遍历销毁链表 
free(*L);
*L = p;
}}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q)//p为链表地址，q为想要插入的结点，函数传递 
 {
if(!p) {printf("指定结点不存在\n"); return ERROR; }

q->next = p->next;
p->next = q;
return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
if (!p) {printf("指定结点不存在"); return ERROR; }
if (!(p->next)) { printf("该节点已是最后一个节点！"); return ERROR; }
LNode *t = p->next;
*e = t->data;
p->next = t->next;//间隔删除节点的节点连接 
free(t);//释放 
return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e))//visit=pri
 {
while(L)//存在及打印 
{
visit(L->data);
L = L->next;
}
printf("\n");
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
while(L){
if(L->data == e)return SUCCESS;
L = L->next;
}
return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {if(!(*L)) return ERROR;//反转链表 
LinkedList p1,p2,p3;
p1 = *L;
p2 = p3 = p1->next;//第二个结点 
p1->next = NULL;
while(p3){
   p3 = p3->next;//先第三个结点，后逐渐增加 即往前前进一步 
   p2->next = p1;
   p1 = p2;
   p2 = p3;
}
*L = p1;//p1为最后一个节点 
return SUCCESS;

}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {if(!L)return ERROR;
LinkedList p1,p2;
p1=p2=L; 
while( (!p1)&&(!p2) )
{
p2 = p2->next->next;//一次跨两个结点，当有循环时，总会出现p1=p2 
p1 = p1->next;
if(p1 == p2)return SUCCESS;
}
return ERROR;

}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
 //奇偶反转 
LNode* ReverseEvenList(LinkedList *L) {
LinkedList p1,p2,h,t;//t主要成为中间的变化量 
int n = 0;
h=p1 = *L;//赋值为头地址 
while(p1->next)
{
p2 = p1->next;
p1->next = p2->next;
p2->next = p1;
if(++n == 1)h = p2;//将头指针设定好 

else t->next = p2;

t = p1;//始终为将要调换的两个节点的，前一个节点 ，要存储地址，t->next为连接而存在 
p1 = p1->next;// 遍历下一个结点，调换顺序后的下一个结点 
if(!p1)break;
}
return h;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
 
LNode* FindMidNode(LinkedList *L) 
{
LinkedList p1,p2;
p1 = p2 = *L;

while (p2)
{
p2 = p2->next->next;
p1 = p1->next;
if (p2->next == NULL) {
printf("中间节点的数据为%d\n",p1->data);
break;
}
if (p2->next->next == NULL) {
printf("中间节点数据为%d-%d\n",p1->data,p1->next->data);
break;
}
}
return p1;
}



