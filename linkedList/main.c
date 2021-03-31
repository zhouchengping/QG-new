#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//菜单栏 
void menu()
{
printf("\t\t\t-----1.销毁链表并退出程序-----------\n");
printf("\t\t\t-----2.插入一个结点-----------------\n");
printf("\t\t\t-----3.删除第几个结点---------------\n");
printf("\t\t\t-----4.遍历链表并输出链表数据-------\n");
printf("\t\t\t-----5.查询链表是否包含某数---------\n");
printf("\t\t\t-----6.反转链表---------------------\n");
printf("\t\t\t-----7.判断链表是否出现循环---------\n");
printf("\t\t\t-----8.将链表中偶数节点和前节点交换-\n");
printf("\t\t\t-----9.查找中间节点---\n");
} 
 //创建链表,因为没有读取文件的操作，每次都要先设计链表 
 LNode* Creat(char a){//创造链表，创造的是反方向的 ，也就是后面接前面 
 	LinkedList head,p1,p2;
 	int n;
 	printf("请输入所需的节点数:");
	scanf("%d",&n); 
 	int i;
 	 
	for(i=1;i<=n;i++)
	{

        if(i == 1) {
            InitList(&head);//调用函数，主要是创造空间，然后将head->next=NULL 
            head->data = i;
            p2=head;//存储最初的地址，因为创建的第一个next为空
        }
        else{
            p1 = (LinkedList)malloc(sizeof(LNode));//创建空间 
            p1->data = i; 
            p1->next = head;//反方向连接链表 
            head = p1;
        }
		}
 	 if(a==1)p2->next=head;
	  return head;
 } 
 
//找到需要用到的节点
LinkedList getNode(LinkedList h,int n)
{int i;
    if(n<1) return NULL;
    LinkedList p = h;
    for(i = 1;i < n;i++)
    {
        p = p->next;
        if(i < n-1 && p->next == NULL)//找到插入的结点，或者删除的结点 
            return NULL;
    }
    return p;

}
//创建一个节点
LinkedList creatNode()
{
    LinkedList q;//想要创建新节点，直接传递 
    q = (LinkedList)malloc(sizeof(LNode));
    printf("请输入您要插入的数据：");
    scanf("%d",&q->data); 
    return q;
}

//输出数据 
void pri(ElemType e)//e 形参，这个函数主要是为了调用输出 
{
    printf("%d->",e);
}


LinkedList L = NULL;

int main(){ 
printf("因为没有读取文件的操作，每次都要先设计链表\n");
	LinkedList head;
	char a[100];
	while(1)
	{printf("是否成为循环链表(1:是 0.否)：");
	gets(a);
	if(strlen(a)==1)
	{
	switch(a[0])
	{case '1':head=Creat(1);break;
	case '0':
		head=Creat(0);
		break;
	default : 
	printf("请认真输入要求：\n");
		break;

	}
	
	if(a[0]=='1')break;
	if(a[0]=='0')break;}
	else printf("请重新输入！\n");
	}  

	while(1)
	{
	menu();
	printf("请输入你选择的程序(1~9),请准确输入：");
	int n;
	ElemType *e;
    e=&n;
	char str[100];
	
	gets(str);
	if(strlen(str)==1)
	{
	switch(str[0])
	{case '1':
		system ("cls");
		DestroyList(&head);
		printf("已将链表销毁\n");
		exit(0); 
	case '2':
		system ("cls");
		printf("请输入在第几个结点后插入:");
		scanf("%d",&n);
		if(InsertList(getNode(head,n), creatNode()))//将创造的结点以及第几个节点后插入输入 ，
		//InsertList函数的形参用函数调用 
		printf("操作成功\n");
        else printf("操作失败\n");
        break;
    case '3':
    	system ("cls");
		printf("请输入你要删除第几个节点：");
                scanf("%d",&n);
                if(DeleteList(getNode(head,n),e))//先寻找要删除的结点，e为DeleteList删除后传递的数据 
				printf("操作成功，删除节点数据为%d\n",*e);
                else printf("操作失败\n");
                break;
 	case '4':
 		system ("cls");
            TraverseList(head,pri);
            printf("打印完成\n"); 
			break;
    case '5':
    	system ("cls");
            printf("请输入要查询的数：");
            scanf("%d",&n);
            if(SearchList(head, n))
			printf("链表中有该数据\n");
            else printf("链表中不存在该数据\n");
            break;
    case '6':
    	system ("cls");
            if(ReverseList(&head))
			printf("操作成功\n");
            else printf("未知错误\n");
            break;
    case '7':
    	system ("cls");
            if(IsLoopList(head))
			printf("链表存在循环\n");
            else printf("链表不存在循环\n");
            break;
    case '8':
    	system ("cls");
        	head = ReverseEvenList(&head);
            printf("操作成功\n");
            break;
    case '9':
    	system ("cls");
            FindMidNode(&head);
            break;
    default :
    	system ("cls");
		printf("\n请在正确的范围输入！\n");
		break; 
        		
	}
	}
	else {printf("请认真输入数字\n"); system("cls"); 
	}
}
}
