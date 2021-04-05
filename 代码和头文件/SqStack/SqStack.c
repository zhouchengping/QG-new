#include<stdio.h>
#include"SqStack.h"



//基于数组的顺序栈
Status initStack(SqStack *s,int sizes)//初始化栈
{if(s)return 1;

else return 0;}


Status isEmptyStack(SqStack *s)//判断栈是否为空
{ if(s->top == -1)
        return 1;
    else
        return 0;}
        
        
        
Status getTopStack(SqStack *s,ElemType *e) //得到栈顶元素
{if(isEmptyStack(s))
        return 0;//栈空
else
{*e=s->elem[s->top];}
        return 1;}
        
        
Status clearStack(SqStack *s)//清空栈
{s->top=-1;
return 1;
 }
 
Status destroyStack(SqStack *s)//销毁栈
{free(s);
return 1;
}

Status stackLength(SqStack *s,int *length)//检测栈长度
{if(s->top==-1)return 0;
else {*length=s->top+1;return 1;
}}
Status pushStack(SqStack *s,ElemType data)//入栈
{if(s->top ==-1||s->top>s->size )
        return 0;//栈满不能入栈
    else{
        s->top++;
        s->elem[s->top] = data;
        return 1;
    }}
Status popStack(SqStack *s,ElemType *data)//出栈
{if(s->top==-1)
        return 0;//栈空不能出栈
    else{
        *data = s->elem[s->top];
        s->top--;
        return 1;
    }//栈顶元素存入*data，返回
	}
