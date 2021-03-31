#include "duLinkedList.h"
  #include <stdio.h>
  #include <stdlib.h>


/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
(*L) = (DuLinkedList)malloc(sizeof(DuLNode));
         if(!(*L))return ERROR;
         (*L)->next = NULL;
         (*L)->prior = NULL;
         return SUCCESS;

}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
 //ɾ��ȫ��������������� 
void DestroyList_DuL(DuLinkedList *L) {
  DuLinkedList p;
         while(*L){
             p = (*L)->next;
             free(*L);//�����ͷſռ� 
             *L = p;
         }
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
 //ǰ������� 
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
if(!p)return ERROR;//Ҫ����������㲻���� 
         if(p->prior){//���ж��ǲ�����ǰһ���ڵ� 
             q->prior = p->prior;//��pǰ����룬 q->priorҪָ��p��ǰһ����� 
             p->prior->next = q;//p��ǰһ�����ָ��q 
         }
         q->next = p;
         p->prior = q;
         return SUCCESS;

}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
 //p q����Ҫ����Ľڵ㣬�ʹ���Ľڵ� 
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
if(!p)return ERROR;//����Ľڵ㲻���� 
         if(p->next){//���ж��ǲ������һ���ڵ� 
             q->next = p->next;
             p->next->prior = q;
         }
         q->prior = p;
         p->next = q;
         return SUCCESS;

}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) //p��ΪҪɾ���Ľڵ� 
{
if (!p) {
             printf("ָ���ڵ㲻���ڣ�\n");
             return ERROR;
         }
         else if (!(p->next)) {
             printf("�ýڵ����û�нڵ㣡\n");
             return ERROR;
         }
         DuLNode *t = p->next;//����һ���ڵ�ĵ�ַ 
         *e = p->next->data;//������ 
         p->next = p->next->next; 
         if (p->next) p->next->prior = p;//�ж��ǲ���Ϊ���Ľڵ� 
         free(t);
         return SUCCESS;

}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
//���� 
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
if(L->prior) L = L->prior;
         while(L){
             visit(L->data);
             L = L->next;
         }
         printf("\n");
}
