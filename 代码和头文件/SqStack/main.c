#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<malloc.h>
#include"Sqstack.h"
void menu()
{printf("\t\t\t---------------------------------");
printf("\t\t\t\t\t1.初始化栈\n");
printf("\t\t\t\t\t2.判断栈是否为空\n");
printf("\t\t\t\t\t3.得到栈顶元素\n");
printf("\t\t\t\t\t4.清空栈\n");
printf("\t\t\t\t\t5.销毁栈\n");
printf("\t\t\t\t\t6.检测栈长度\n");
printf("\t\t\t\t\t7.入栈\n");
printf("\t\t\t\t\t8.出栈\n");
printf("\t\t\t---------------------------------");
}
//栈初始化
SqStack* Init_SqStack(int a)
{  
    SqStack* s;
    int n;
    s = (SqStack*)malloc(sizeof(SqStack));
    if(!s){
        printf("空间不足\n");
        return NULL;
    }else
	{
        s->top=-1;
       	s->size=a;
       	for(n=0;n<a;n++)
       	{
		printf("输入要初始化的数据：");
       	scanf("%d",s->elem[n]);
       	printf("现在的数据长度：%d",n);
       	s->top=n;}
        return s;
    }
    
void traverse(SqStack *s)		//遍历栈中元素并进行打印 
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
printf("请输入你的选择：");
scanf("%s",a);
if(strlen(a)==1)
{switch(a[0])
{case '1':
	printf("请输入栈的容量大小：");
	scanf("%d",&i);
	head=SqStack* Init_SqStack(i);
	 if(Status initStack(head,i))
	 {traverse(&head);
	 printf("初始化成功！\n");
	 }
	 else
	 printf("初始化失败！\n");
	 break;
case '2'://判断栈是否为空 
	if(Status isEmptyStack(head))
	printf("栈不为空\n");
	else
	printf("栈为空\n");
	break;
case '3'://得到栈顶元素
	if(Status getTopStack(head,ElemType *e))
	printf("栈顶元素 e=%d!!\n",*e);
	else
	printf("没有栈顶元素！！\n"); 
	break;
case '4':
	if(Status clearStack(head))//清空栈
	printf("栈已经清空！！\n");
	else
	printf("未找到栈，不能进行清空！！\n");
case '5':
	if(Status destroyStack(head))//销毁栈
	printf("栈已经被销毁！！！\n");
	else("未找到栈，不能进行销毁！！\n") ;
	break;
case '6':
	int *length=0;
	if(Status stackLength(head,*length))//检测栈长度
	printf("栈的长度为：%d",*length);
	else("未找到栈，不能测量长度！！\n") ;
	break;
case '7':
	printf("请输入需要入栈的数据：");
	scanf("%d",i);
	if(Status pushStack(head,i);//入栈
	{printf("入栈成功！！\n");
	traverse(&head);
	}
	else
	printf("入栈失败！！\n");
	break;
case '8':
	printf("请输入要出栈的数据：");
	scanf("%d",i);
	if(Status popStack(head,ElemType *data);
	traverse(&head);
	break;
}

}
else
printf("输入错误！\n");
} 

}  


