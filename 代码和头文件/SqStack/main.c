#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<malloc.h>
#include"Sqstack.h"
void menu()
{printf("\t\t\t---------------------------------");
printf("\t\t\t\t\t1.��ʼ��ջ\n");
printf("\t\t\t\t\t2.�ж�ջ�Ƿ�Ϊ��\n");
printf("\t\t\t\t\t3.�õ�ջ��Ԫ��\n");
printf("\t\t\t\t\t4.���ջ\n");
printf("\t\t\t\t\t5.����ջ\n");
printf("\t\t\t\t\t6.���ջ����\n");
printf("\t\t\t\t\t7.��ջ\n");
printf("\t\t\t\t\t8.��ջ\n");
printf("\t\t\t---------------------------------");
}
//ջ��ʼ��
SqStack* Init_SqStack(int a)
{  
    SqStack* s;
    int n;
    s = (SqStack*)malloc(sizeof(SqStack));
    if(!s){
        printf("�ռ䲻��\n");
        return NULL;
    }else
	{
        s->top=-1;
       	s->size=a;
       	for(n=0;n<a;n++)
       	{
		printf("����Ҫ��ʼ�������ݣ�");
       	scanf("%d",s->elem[n]);
       	printf("���ڵ����ݳ��ȣ�%d",n);
       	s->top=n;}
        return s;
    }
    
void traverse(SqStack *s)		//����ջ��Ԫ�ز����д�ӡ 
{
	int i = 0;
	while(i <= s->top)			 
		{
	printf("%d",s->elme[i++]);
	printf("\n");
}
int main()
{SqStack *head;
char a[100];
int i;
int *e;
while(1)
{
menu();
printf("���������ѡ��");
scanf("%s",a);
if(strlen(a)==1)
{switch(a[0])
{case '1':
	printf("������ջ��������С��");
	scanf("%d",&i);
	head=SqStack* Init_SqStack(i);
	 if(Status initStack(head,i))
	 {traverse(&head);
	 printf("��ʼ���ɹ���\n");
	 }
	 else
	 printf("��ʼ��ʧ�ܣ�\n");
	 break;
case '2'://�ж�ջ�Ƿ�Ϊ�� 
	if(Status isEmptyStack(head))
	printf("ջ��Ϊ��\n");
	else
	printf("ջΪ��\n");
	break;
case '3'://�õ�ջ��Ԫ��
	if(Status getTopStack(head,ElemType *e))
	printf("ջ��Ԫ�� e=%d!!\n",*e);
	else
	printf("û��ջ��Ԫ�أ���\n"); 
	break;
case '4':
	if(Status clearStack(head))//���ջ
	printf("ջ�Ѿ���գ���\n");
	else
	printf("δ�ҵ�ջ�����ܽ�����գ���\n");
case '5':
	if(Status destroyStack(head))//����ջ
	printf("ջ�Ѿ������٣�����\n");
	else("δ�ҵ�ջ�����ܽ������٣���\n") ;
	break;
case '6':
	int *length=0;
	if(Status stackLength(head,*length))//���ջ����
	printf("ջ�ĳ���Ϊ��%d",*length);
	else("δ�ҵ�ջ�����ܲ������ȣ���\n") ;
	break;
case '7':
	printf("��������Ҫ��ջ�����ݣ�");
	scanf("%d",i);
	if(Status pushStack(head,i);//��ջ
	{printf("��ջ�ɹ�����\n");
	traverse(&head);
	}
	else
	printf("��ջʧ�ܣ���\n");
	break;
case '8':
	printf("������Ҫ��ջ�����ݣ�");
	scanf("%d",i);
	if(Status popStack(head,ElemType *data);
	traverse(&head);
	break;
}

}
else
printf("�������\n");
} 

}  


