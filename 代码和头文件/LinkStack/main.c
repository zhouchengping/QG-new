#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "LinkStack.h"



void menu()
{printf("\t\t\t---------------------------------\n");
printf("\t\t\t\t\t1.��ʼ��ջ\n");
printf("\t\t\t\t\t2.�ж�ջ�Ƿ�Ϊ��\n");
printf("\t\t\t\t\t3.�õ�ջ��Ԫ��\n");
printf("\t\t\t\t\t4.���ջ\n");
printf("\t\t\t\t\t5.����ջ\n");
printf("\t\t\t\t\t6.���ջ����\n");
printf("\t\t\t\t\t7.��ջ\n");
printf("\t\t\t\t\t8.��ջ\n");
printf("\t\t\t---------------------------------\n");
} 
void visit(int p)
{
	printf("%d ", p);
}

void traversestack(LinkStack *s)
{
	LinkStackPtr p;
	p = s->top;
	while(p)
	{
		visit(p -> data);
		p = p -> next;
	}
	printf("\n");
	
}

int main()
{LinkStack head;
int e=0;
int i;
int j;
char a[100];
while(1){

menu();
printf("���������ѡ��");
scanf("%s",a);
if(strlen(a)==1)
{switch(a[0])
{
case'1':
	system("cls"); 
	 if(initLStack(&head))
	 {printf("��ʼ���ɹ���\n");
	 printf("����ڵ�ĳ��ȣ�");
	 scanf("%d",&i);
	 for(j = 1;j <= i;j++)
	 {printf("������� %d ��Ԫ�ص�ֵ��",j);
	 scanf("%d",&e);
	 pushLStack(&head,e);
	 }     
	 }
	 else
	 printf("��ʼ��ʧ�ܣ�\n");
	 break;
case'2'://�ж�ջ�Ƿ�Ϊ�� 
system("cls"); 
	if(isEmptyLStack(&head))
	printf("ջΪ��\n");
	else
	printf("ջ��Ϊ��\n");
	break;
case'3':
	system("cls"); 
	if(getTopLStack(&head,&e))
	printf("ջ��Ԫ�� e=%d!!\n",e);
	else
	printf("û��ջ��Ԫ�أ���\n"); 
	break;
case'4':
	system("cls"); 
	if(clearLStack(&head))//���ջ
	printf("ջ�Ѿ���գ���\n");
	else
	printf("δ�ҵ�ջ�����ܽ�����գ���\n");
	break; 
case'5':
	system("cls"); 
	if(destroyLStack(&head))//����ջ
	printf("ջ�Ѿ������٣�����\n");
	else
	printf("δ�ҵ�ջ�����ܽ������٣���\n") ;
	break;
case'6':
	system("cls"); 
	if(LStackLength(&head,&e))//���ջ����
	printf("ջ�ĳ���Ϊ��%d",e);
	else
	printf("δ�ҵ�ջ�����ܲ������ȣ���\n") ;
	break;
case '7':
	system("cls"); 
	printf("��������Ҫ��ջ�����ݣ�");
	scanf("%d",&i);
	if(pushLStack(&head,i))//��ջ
	{printf("��ջ�ɹ�����\n");
	traversestack(&head);
	}
	else
	printf("��ջʧ�ܣ���\n");
	break;
case '8':
	system("cls"); 
if(popLStack(&head,&e))
	{printf("�����ջ�����ݣ�%d\n",e);
	traversestack(&head);
	}
	else
	printf("ջ�����ڣ���\n");
	break;
default:
	
	printf("������󣡣�\n"); 
}

}
else
printf("�������\n");
} 

}  


