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
	   printf("\t\t\t|******��ѡ���������****************|\n");
       printf("\t\t\t|-----1.���������˳�����-----------|\n");
       printf("\t\t\t|-----2.����һ���ڵ㵽����ָ���ڵ�ǰ-|\n");
       printf("\t\t\t|-----3.����һ���ڵ㵽����ָ���ڵ��-|\n");
       printf("\t\t\t|-----4.ɾ��һ���ڵ㲢����ڵ�����---|\n");
       printf("\t\t\t|-----5.�������������������-------|\n");
       printf("\t\t\t--------------------------------------\n");
} 
DuLNode* Creat()
{
   DuLinkedList p1,p2,head;
	int i;
  	int n;
 	printf("����������Ľڵ���(1-100):");
	scanf("%d",&n);
	head=p1;

	  
   for(i = 1;i <= n;i++)
       if(i == 1) {
           InitList_DuL(&head);//��ַ���ݴ�����һ����㣬Ȼ���Ϊ���һ���ڵ� 
           head->data = i;
           p1 = head;
       }
       else{
           p2 = (DuLinkedList)malloc(sizeof(DuLNode));
           p2->data = i;
           p2->next = NULL;//������Ϊnull���´�ѭ��ʱ������һ���ڵ� 
           p2->prior = p1;//ָ��ǰһ����� 
           p1->next = p2;//������� 
           p1 = p2;// ���ӽ��� 
       }    
	   printf("�����ɹ�������\n");  
	   
   return head;//����ͷ��ַ 

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
   printf("��ѡ����Ҫ���еĲ�����");
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
           printf("��������Ҫ�ڵڼ����ڵ�ǰ���룺");
           scanf("%d",&a);
           if(InsertBeforeList_DuL(getNode(head,a), creatNode())) printf("�����ɹ�\n");
           else printf("����ʧ�ܣ�ָ���ڵ㲻����\n");
           head = refresh(head);
           break;
       case '3':
       	system ("cls");
           printf("��������Ҫ�ڵڼ����ڵ�����룺");
           scanf("%d",&a);
           if(InsertAfterList_DuL(getNode(head,a), creatNode())) printf("�����ɹ�\n");
           else printf("����ʧ�ܣ�ָ���ڵ㲻����\n");
           break;
       case '4':
       	system ("cls");
          printf("��������Ҫɾ���ڼ���㣬��������ݣ�");
           scanf("%d",&a);
           if(DeleteList_DuL(getNode(head,a),e)) printf("�����ɹ���ɾ���ڵ�����Ϊ%d\n",*e);
           else printf("����ʧ��");
           break;
       case '5':
       	system ("cls");
           TraverseList_DuL(head,pri);
           printf("��������ɹ�\n"); 
		   break;
       default :
	   	printf("������ȷ�ķ�Χ���룡\n");
       		break;
   }
}
else {printf("����ȷ��������!\n");system("cls");
}
 }
}

//�ҵ���Ҫ�õ��Ľڵ�
DuLinkedList getNode(DuLinkedList h,int n)//��������һ�������ó� 
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
//����һ���ڵ�
DuLinkedList creatNode()
{
   DuLinkedList q;
   q = (DuLinkedList)malloc(sizeof(DuLNode));//�����ռ� 
   printf("��������Ҫ��������ݣ�");
   scanf("%d",&q->data); 
   q->next = q->prior = NULL;//���趨Ϊ�� 
   return q;//���ص�ַ 
}
//��ӡ���ݣ���������һ�� 
void pri(ElemType e)
{
   printf("%d->",e);
}

DuLinkedList refresh(DuLinkedList h)
{
   while(h->prior) h = h->prior;
   return h;

}

