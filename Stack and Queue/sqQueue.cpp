#include<bits/stdc++.h>
#include<stdlib.h>
#define MAXSIZE 10
using namespace std;
typedef char elemType;
struct sqQueue
{
    elemType data[MAXSIZE];
    int front, rear;
}qu;

void queueInitial(sqQueue *&qu)
{
    qu= new sqQueue;
    qu-> front= qu-> rear= 0;
}

void queueDestroy(sqQueue *&qu)
{
    delete []qu;
}

bool queueEmpty(sqQueue *qu)
{
    if(qu-> front== qu-> rear) {return true;}
    else {return false ;}
}

bool queueFull(sqQueue *qu)
{
    if((qu-> rear+ 1) %MAXSIZE== qu-> front) {return true;}
    else {return false;}
}

void queueEn(sqQueue *&qu, elemType value)
{
    if(queueFull(qu)== 1)
    {
        cout<< "队列已满"<< endl;
        return;
    }

/*  
    else
    {
        qu-> rear++;     
        qu-> data[qu-> rear]= value;
    }

*/

    else
    {
        qu-> rear= (qu-> rear+ 1)% MAXSIZE;
        qu-> data[qu-> rear]= value;
    }
}

void queueDe(sqQueue *&qu)
{
    if(queueEmpty(qu)== 1) 
    {
        cout<< "队列已空"<< endl;
        return;
    }
    else
    {
        qu-> front= (qu-> front+ 1)% MAXSIZE;
    }
}

void queueDisp(sqQueue *qu)
{
    if(queueEmpty(qu)== 1)
    {
        cout<< "队列已空，无法输出数据"<< endl;
        return;
    }
    else
    {
        int i= qu-> front;
        while(i!= qu-> rear)
        {
            cout<< qu-> data[i]<< " ";
            i= (i+ 1)% MAXSIZE;
        }
        cout<< endl;
    }
}

int main()
{
    sqQueue *q;
    queueInitial(q);
    
    for(int i= 0; i< 10; i++)
    {
        queueEn(q, 'a'+ i);
    }

    queueDe(q);
    queueDisp(q);
    queueDestroy(q);
}