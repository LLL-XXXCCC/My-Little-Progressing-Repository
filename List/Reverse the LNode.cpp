/*
对于正在使用的链表的指针，不能删除，而是建立destroy函数，操作完之后再删除
*/

#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
typedef int elemType;
struct Node
{
    elemType data;
    struct Node *next;
}*head, *newhead;

void nodeCreate(Node *&head, Node *&newhead, elemType a[], int n)
{
    Node *cur, *tail;
    head= new Node;
    tail= head;
    for(int i= 0; i< n; i++)
    {
        cur= new Node;
        cur-> data= a[i];
        cur-> next= NULL;
        tail-> next= cur;
        tail= cur;
    }    
    newhead= new Node;
    newhead-> next= NULL;
}

/*头插法建立单链表实现反转，但是同样地要有一个头结点不保存数据*/
void nodeReverse(Node *&head, Node *&newhead, int n)
{
    Node *cur, *p= head-> next;
    for(int i= 0; i< n; i++)
    {
        cur= new Node;
        cur-> data= p-> data;
        cur-> next= newhead-> next;
        newhead-> next= cur;
        p= p-> next;
    }
}

void nodeDisp(Node *x)
{
    Node *p= x-> next;
    while(p!= NULL)
    {
        cout<< p-> data<< " ";
        p= p-> next;
    }
    delete[] p;
}

void nodeDestroy(Node *x)
{
    Node *pre, *p;
    pre= x, p= pre-> next;
    while(p!= NULL)
    {
        delete pre;
        pre= p;
        p= pre-> next;
    }
    delete[] pre;
}

int main()
{
    cout<< "请输入单链表的长度：";
    int len;
    cin>> len;
    elemType a[len];
    cout<< "请输入反转前的单链表：";
    for(int i= 0; i< len; i++)
    {
        cin>> a[i];
    }
    nodeCreate(head, newhead, a, len);
    nodeReverse(head, newhead, len);
    cout<< "反转后的单链表：";
    nodeDisp(newhead);
}