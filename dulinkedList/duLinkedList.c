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
 //删除全部链表跟单链表差不多 
void DestroyList_DuL(DuLinkedList *L) {
  DuLinkedList p;
         while(*L){
             p = (*L)->next;
             free(*L);//遍历释放空间 
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
 //前面插入结点 
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
if(!p)return ERROR;//要插入的链表结点不存在 
         if(p->prior){//先判断是不是最前一个节点 
             q->prior = p->prior;//在p前面插入， q->prior要指向p的前一个结点 
             p->prior->next = q;//p的前一个结点指向q 
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
 //p q仍是要插入的节点，和创造的节点 
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
if(!p)return ERROR;//插入的节点不存在 
         if(p->next){//先判断是不是最后一个节点 
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
Status DeleteList_DuL(DuLNode *p, ElemType *e) //p即为要删除的节点 
{
if (!p) {
             printf("指定节点不存在！\n");
             return ERROR;
         }
         else if (!(p->next)) {
             printf("该节点后面没有节点！\n");
             return ERROR;
         }
         DuLNode *t = p->next;//存下一个节点的地址 
         *e = p->next->data;//存数据 
         p->next = p->next->next; 
         if (p->next) p->next->prior = p;//判断是不是为最后的节点 
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
//遍历 
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
if(L->prior) L = L->prior;
         while(L){
             visit(L->data);
             L = L->next;
         }
         printf("\n");
}
