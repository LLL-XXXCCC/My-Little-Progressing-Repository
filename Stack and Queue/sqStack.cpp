#include<bits/stdc++.h>
#include<stdlib.h>
#define MAXSIZE 20
using namespace std;
typedef char elemType;
struct sqStack
{
    int top;
    elemType data[MAXSIZE];
};

void stackInitial(sqStack *&s)
{
    s= new sqStack;
    s-> top= -1;
}

void stackDestroy(sqStack *&s)
{
    delete []s;
}

bool stackEmpty(sqStack *s)
{
    if(s-> top== -1) {return true;}
    else {return false;}
}

void stackPush(sqStack *&s, elemType value)
{
    if(s-> top>= MAXSIZE- 1)
    {
        cout<< "错误原因：栈已满"<< endl;
        return;
    }
    else
    {
        s-> top++;
        s-> data[s-> top]= value;
    }
}

elemType stackPop(sqStack *&s)
{
    if(s-> top== -1)
    {
        cout<< "错误原因：空栈"<< endl;
    }
    else
    {
        elemType value= s-> data[s-> top];
        s-> top--;
        return value;
    }
}

void stackDisp(sqStack *s)
{
    if(stackEmpty(s)== 1)
    {
        cout<< "该栈是空栈"<< endl;
        return;
    }
    else
    {
        while(s-> top!= -1)
        {
            cout<< s-> data[s-> top]<< endl;
            s-> top--;
        }
    }
}

int main()
{
    sqStack *s;
    stackInitial(s);
    for(int i= 0; i< 5; i++)
    {
        stackPush(s, 'a'+ i);
    }
    if(stackEmpty(s)== 1) {cout<< "该栈是空栈";}
    else {cout<< "该栈不是空栈";}
    stackDisp(s);
}