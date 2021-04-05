#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "LinkStack.h"



void menu()
{printf("\t\t\t---------------------------------\n");
printf("\t\t\t\t\t1.初始化栈\n");
printf("\t\t\t\t\t2.判断栈是否为空\n");
printf("\t\t\t\t\t3.得到栈顶元素\n");
printf("\t\t\t\t\t4.清空栈\n");
printf("\t\t\t\t\t5.销毁栈\n");
printf("\t\t\t\t\t6.检测栈长度\n");
printf("\t\t\t\t\t7.入栈\n");
printf("\t\t\t\t\t8.出栈\n");
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
printf("请输入你的选择：");
scanf("%s",a);
if(strlen(a)==1)
{switch(a[0])
{
case'1':
	system("cls"); 
	 if(initLStack(&head))
	 {printf("初始化成功！\n");
	 printf("输入节点的长度：");
	 scanf("%d",&i);
	 for(j = 1;j <= i;j++)
	 {printf("请输入第 %d 个元素的值：",j);
	 scanf("%d",&e);
	 pushLStack(&head,e);
	 }     
	 }
	 else
	 printf("初始化失败！\n");
	 break;
case'2'://判断栈是否为空 
system("cls"); 
	if(isEmptyLStack(&head))
	printf("栈为空\n");
	else
	printf("栈不为空\n");
	break;
case'3':
	system("cls"); 
	if(getTopLStack(&head,&e))
	printf("栈顶元素 e=%d!!\n",e);
	else
	printf("没有栈顶元素！！\n"); 
	break;
case'4':
	system("cls"); 
	if(clearLStack(&head))//清空栈
	printf("栈已经清空！！\n");
	else
	printf("未找到栈，不能进行清空！！\n");
	break; 
case'5':
	system("cls"); 
	if(destroyLStack(&head))//销毁栈
	printf("栈已经被销毁！！！\n");
	else
	printf("未找到栈，不能进行销毁！！\n") ;
	break;
case'6':
	system("cls"); 
	if(LStackLength(&head,&e))//检测栈长度
	printf("栈的长度为：%d",e);
	else
	printf("未找到栈，不能测量长度！！\n") ;
	break;
case '7':
	system("cls"); 
	printf("请输入需要入栈的数据：");
	scanf("%d",&i);
	if(pushLStack(&head,i))//入栈
	{printf("入栈成功！！\n");
	traversestack(&head);
	}
	else
	printf("入栈失败！！\n");
	break;
case '8':
	system("cls"); 
if(popLStack(&head,&e))
	{printf("输出出栈的数据：%d\n",e);
	traversestack(&head);
	}
	else
	printf("栈不存在！！\n");
	break;
default:
	
	printf("输入错误！！\n"); 
}

}
else
printf("输入错误！\n");
} 

}  


