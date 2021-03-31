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
*L = (LinkedList)malloc(sizeof(LNode));//���ռ� 
        if(!(*L)) return ERROR;//�ж� 
        (*L)->next =NULL;//��Creat()��������ʱ������� 
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
p = (*L)->next;//������������ 
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
Status InsertList(LNode *p, LNode *q)//pΪ�����ַ��qΪ��Ҫ����Ľ�㣬�������� 
 {
if(!p) {printf("ָ����㲻����\n"); return ERROR; }

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
if (!p) {printf("ָ����㲻����"); return ERROR; }
if (!(p->next)) { printf("�ýڵ��������һ���ڵ㣡"); return ERROR; }
LNode *t = p->next;
*e = t->data;
p->next = t->next;//���ɾ���ڵ�Ľڵ����� 
free(t);//�ͷ� 
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
while(L)//���ڼ���ӡ 
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
Status ReverseList(LinkedList *L) {if(!(*L)) return ERROR;//��ת���� 
LinkedList p1,p2,p3;
p1 = *L;
p2 = p3 = p1->next;//�ڶ������ 
p1->next = NULL;
while(p3){
   p3 = p3->next;//�ȵ�������㣬�������� ����ǰǰ��һ�� 
   p2->next = p1;
   p1 = p2;
   p2 = p3;
}
*L = p1;//p1Ϊ���һ���ڵ� 
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
p2 = p2->next->next;//һ�ο�������㣬����ѭ��ʱ���ܻ����p1=p2 
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
 //��ż��ת 
LNode* ReverseEvenList(LinkedList *L) {
LinkedList p1,p2,h,t;//t��Ҫ��Ϊ�м�ı仯�� 
int n = 0;
h=p1 = *L;//��ֵΪͷ��ַ 
while(p1->next)
{
p2 = p1->next;
p1->next = p2->next;
p2->next = p1;
if(++n == 1)h = p2;//��ͷָ���趨�� 

else t->next = p2;

t = p1;//ʼ��Ϊ��Ҫ�����������ڵ�ģ�ǰһ���ڵ� ��Ҫ�洢��ַ��t->nextΪ���Ӷ����� 
p1 = p1->next;// ������һ����㣬����˳������һ����� 
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
printf("�м�ڵ������Ϊ%d\n",p1->data);
break;
}
if (p2->next->next == NULL) {
printf("�м�ڵ�����Ϊ%d-%d\n",p1->data,p1->next->data);
break;
}
}
return p1;
}



