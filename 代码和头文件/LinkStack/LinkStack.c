#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LinkStack.h"

//��ջ
Status initLStack(LinkStack *s)//��ʼ��ջ
{s-> top = (LinkStackPtr)malloc(sizeof(StackNode));
        if(!(s-> top))
    	return ERROR;
        s -> top = NULL;
        s -> count = 0;
        return SUCCESS;
}



Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{if(s->count==0)
return SUCCESS;
else 
return ERROR;} 



Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
{if(isEmptyLStack(s))//��ջû��ջ��
return ERROR;
*e=s->top->data;
return SUCCESS; 
}



Status clearLStack(LinkStack *s)//���ջ
{if(s->top->next==NULL)return ERROR;
LinkStackPtr p,q;
while(s->count>0){q=p->next;
free(p);
s->count--;
p=q; 
}return SUCCESS;}




Status destroyLStack(LinkStack *s)//����ջ
{if(s->top->next==NULL)return ERROR;
LinkStackPtr p,q;
p=s->top;
while(s->count>0)
{q=p->next;
free(p);
s->count--;
p=q;
}
free(s->top);
s->top=NULL;
return SUCCESS;}


Status LStackLength(LinkStack *s,int *length)//���ջ����
{if(isEmptyLStack(s))
return ERROR;
*length=s->count;
return SUCCESS;}



Status pushLStack(LinkStack *s,ElemType data)//��ջ
{LinkStackPtr p;
p=(LinkStackPtr)malloc(sizeof(StackNode));
p->next=s->top;
p->data=data;
s->top=p;
s->count++;
return SUCCESS;}




Status popLStack(LinkStack *s,ElemType *data)//��ջ
{if(isEmptyLStack(s))
return ERROR;
LinkStackPtr p;
*data=s->top->data;
p=s->top;
s->top=p->next;
s->count--;
return SUCCESS;}
