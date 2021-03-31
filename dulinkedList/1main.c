#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void pri(ElemType e);
DuLinkedList refresh(DuLinkedList h);
DuLinkedList getNode(DuLinkedList h,int n);
DuLinkedList creatNode();


void menu(){
	   printf("\t\t\t--------------------------------------\n");
	   printf("\t\t\t|******请选择链表操作****************|\n");
       printf("\t\t\t|-----1.销毁链表并退出程序-----------|\n");
       printf("\t\t\t|-----2.插入一个节点到链表指定节点前-|\n");
       printf("\t\t\t|-----3.插入一个节点到链表指定节点后-|\n");
       printf("\t\t\t|-----4.删除一个节点并输出节点数据---|\n");
       printf("\t\t\t|-----5.遍历链表并输出链表数据-------|\n");
       printf("\t\t\t--------------------------------------\n");
} 
DuLNode* Creat()
{
   DuLinkedList p1,p2,head;
	int i;
  	int n;
 	printf("请输入所需的节点数(1-100):");
	scanf("%d",&n);
	head=p1;

	  
   for(i = 1;i <= n;i++)
       if(i == 1) {
           InitList_DuL(&head);//地址传递创建第一个结点，然后变为最后一个节点 
           head->data = i;
           p1 = head;
       }
       else{
           p2 = (DuLinkedList)malloc(sizeof(DuLNode));
           p2->data = i;
           p2->next = NULL;//先设置为null，下次循环时给到下一个节点 
           p2->prior = p1;//指向前一个结点 
           p1->next = p2;//结点连接 
           p1 = p2;// 增加节数 
       }    
	   printf("创建成功！！！\n");  
	   
   return head;//返回头地址 

}
void main()
{DuLinkedList head;
head=Creat();
   char str[100];
   int a,*e;
   e = &a;
   while(1)
   {
  
   menu();
   printf("请选择你要进行的操作：");
   gets(str);
   
   if(strlen(str)==1)
   {
   
   switch(str[0]) {
       case '1':
       		system ("cls");
           DestroyList_DuL(&head);
           exit(0);
       case '2':
       		system ("cls");
           printf("请输入你要在第几个节点前插入：");
           scanf("%d",&a);
           if(InsertBeforeList_DuL(getNode(head,a), creatNode())) printf("操作成功\n");
           else printf("操作失败：指定节点不存在\n");
           head = refresh(head);
           break;
       case '3':
       	system ("cls");
           printf("请输入你要在第几个节点后后插入：");
           scanf("%d",&a);
           if(InsertAfterList_DuL(getNode(head,a), creatNode())) printf("操作成功\n");
           else printf("操作失败：指定节点不存在\n");
           break;
       case '4':
       	system ("cls");
          printf("请输入你要删除第几结点，并输出数据：");
           scanf("%d",&a);
           if(DeleteList_DuL(getNode(head,a),e)) printf("操作成功，删除节点数据为%d\n",*e);
           else printf("操作失败");
           break;
       case '5':
       	system ("cls");
           TraverseList_DuL(head,pri);
           printf("链表输出成工\n"); 
		   break;
       default :
	   	printf("请在正确的范围输入！\n");
       		break;
   }
}
else {printf("请正确输入数字!\n");system("cls");
}
 }
}

//找到需要用到的节点
DuLinkedList getNode(DuLinkedList h,int n)//跟单链表一样遍历得出 
{int i;
   if(n<1) return NULL;
   DuLinkedList p = h;

   for( i= 1;i < n;i++)
   {
       p = p->next;
       if(i < n-1 && p->next == NULL)
           return NULL;
   }
   return p;

}
//创建一个节点
DuLinkedList creatNode()
{
   DuLinkedList q;
   q = (DuLinkedList)malloc(sizeof(DuLNode));//创建空间 
   printf("请输入您要插入的数据：");
   scanf("%d",&q->data); 
   q->next = q->prior = NULL;//先设定为空 
   return q;//返回地址 
}
//打印数据，跟单链表一样 
void pri(ElemType e)
{
   printf("%d->",e);
}

DuLinkedList refresh(DuLinkedList h)
{
   while(h->prior) h = h->prior;
   return h;

}

