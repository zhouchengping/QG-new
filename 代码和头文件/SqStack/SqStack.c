#include<stdio.h>
#include"SqStack.h"



//���������˳��ջ
Status initStack(SqStack *s,int sizes)//��ʼ��ջ
{if(s)return 1;

else return 0;}


Status isEmptyStack(SqStack *s)//�ж�ջ�Ƿ�Ϊ��
{ if(s->top == -1)
        return 1;
    else
        return 0;}
        
        
        
Status getTopStack(SqStack *s,ElemType *e) //�õ�ջ��Ԫ��
{if(isEmptyStack(s))
        return 0;//ջ��
else
{*e=s->elem[s->top];}
        return 1;}
        
        
Status clearStack(SqStack *s)//���ջ
{s->top=-1;
return 1;
 }
 
Status destroyStack(SqStack *s)//����ջ
{free(s);
return 1;
}

Status stackLength(SqStack *s,int *length)//���ջ����
{if(s->top==-1)return 0;
else {*length=s->top+1;return 1;
}}
Status pushStack(SqStack *s,ElemType data)//��ջ
{if(s->top ==-1||s->top>s->size )
        return 0;//ջ��������ջ
    else{
        s->top++;
        s->elem[s->top] = data;
        return 1;
    }}
Status popStack(SqStack *s,ElemType *data)//��ջ
{if(s->top==-1)
        return 0;//ջ�ղ��ܳ�ջ
    else{
        *data = s->elem[s->top];
        s->top--;
        return 1;
    }//ջ��Ԫ�ش���*data������
	}
