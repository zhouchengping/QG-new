#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�˵��� 
void menu()
{
printf("\t\t\t-----1.���������˳�����-----------\n");
printf("\t\t\t-----2.����һ�����-----------------\n");
printf("\t\t\t-----3.ɾ���ڼ������---------------\n");
printf("\t\t\t-----4.�������������������-------\n");
printf("\t\t\t-----5.��ѯ�����Ƿ����ĳ��---------\n");
printf("\t\t\t-----6.��ת����---------------------\n");
printf("\t\t\t-----7.�ж������Ƿ����ѭ��---------\n");
printf("\t\t\t-----8.��������ż���ڵ��ǰ�ڵ㽻��-\n");
printf("\t\t\t-----9.�����м�ڵ�---\n");
} 
 //��������,��Ϊû�ж�ȡ�ļ��Ĳ�����ÿ�ζ�Ҫ��������� 
 LNode* Creat(char a){//��������������Ƿ������ ��Ҳ���Ǻ����ǰ�� 
 	LinkedList head,p1,p2;
 	int n;
 	printf("����������Ľڵ���:");
	scanf("%d",&n); 
 	int i;
 	 
	for(i=1;i<=n;i++)
	{

        if(i == 1) {
            InitList(&head);//���ú�������Ҫ�Ǵ���ռ䣬Ȼ��head->next=NULL 
            head->data = i;
            p2=head;//�洢����ĵ�ַ����Ϊ�����ĵ�һ��nextΪ��
        }
        else{
            p1 = (LinkedList)malloc(sizeof(LNode));//�����ռ� 
            p1->data = i; 
            p1->next = head;//�������������� 
            head = p1;
        }
		}
 	 if(a==1)p2->next=head;
	  return head;
 } 
 
//�ҵ���Ҫ�õ��Ľڵ�
LinkedList getNode(LinkedList h,int n)
{int i;
    if(n<1) return NULL;
    LinkedList p = h;
    for(i = 1;i < n;i++)
    {
        p = p->next;
        if(i < n-1 && p->next == NULL)//�ҵ�����Ľ�㣬����ɾ���Ľ�� 
            return NULL;
    }
    return p;

}
//����һ���ڵ�
LinkedList creatNode()
{
    LinkedList q;//��Ҫ�����½ڵ㣬ֱ�Ӵ��� 
    q = (LinkedList)malloc(sizeof(LNode));
    printf("��������Ҫ��������ݣ�");
    scanf("%d",&q->data); 
    return q;
}

//������� 
void pri(ElemType e)//e �βΣ����������Ҫ��Ϊ�˵������ 
{
    printf("%d->",e);
}


LinkedList L = NULL;

int main(){ 
printf("��Ϊû�ж�ȡ�ļ��Ĳ�����ÿ�ζ�Ҫ���������\n");
	LinkedList head;
	char a[100];
	while(1)
	{printf("�Ƿ��Ϊѭ������(1:�� 0.��)��");
	gets(a);
	if(strlen(a)==1)
	{
	switch(a[0])
	{case '1':head=Creat(1);break;
	case '0':
		head=Creat(0);
		break;
	default : 
	printf("����������Ҫ��\n");
		break;

	}
	
	if(a[0]=='1')break;
	if(a[0]=='0')break;}
	else printf("���������룡\n");
	}  

	while(1)
	{
	menu();
	printf("��������ѡ��ĳ���(1~9),��׼ȷ���룺");
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
		printf("�ѽ���������\n");
		exit(0); 
	case '2':
		system ("cls");
		printf("�������ڵڼ����������:");
		scanf("%d",&n);
		if(InsertList(getNode(head,n), creatNode()))//������Ľ���Լ��ڼ����ڵ��������� ��
		//InsertList�������β��ú������� 
		printf("�����ɹ�\n");
        else printf("����ʧ��\n");
        break;
    case '3':
    	system ("cls");
		printf("��������Ҫɾ���ڼ����ڵ㣺");
                scanf("%d",&n);
                if(DeleteList(getNode(head,n),e))//��Ѱ��Ҫɾ���Ľ�㣬eΪDeleteListɾ���󴫵ݵ����� 
				printf("�����ɹ���ɾ���ڵ�����Ϊ%d\n",*e);
                else printf("����ʧ��\n");
                break;
 	case '4':
 		system ("cls");
            TraverseList(head,pri);
            printf("��ӡ���\n"); 
			break;
    case '5':
    	system ("cls");
            printf("������Ҫ��ѯ������");
            scanf("%d",&n);
            if(SearchList(head, n))
			printf("�������и�����\n");
            else printf("�����в����ڸ�����\n");
            break;
    case '6':
    	system ("cls");
            if(ReverseList(&head))
			printf("�����ɹ�\n");
            else printf("δ֪����\n");
            break;
    case '7':
    	system ("cls");
            if(IsLoopList(head))
			printf("�������ѭ��\n");
            else printf("��������ѭ��\n");
            break;
    case '8':
    	system ("cls");
        	head = ReverseEvenList(&head);
            printf("�����ɹ�\n");
            break;
    case '9':
    	system ("cls");
            FindMidNode(&head);
            break;
    default :
    	system ("cls");
		printf("\n������ȷ�ķ�Χ���룡\n");
		break; 
        		
	}
	}
	else {printf("��������������\n"); system("cls"); 
	}
}
}
