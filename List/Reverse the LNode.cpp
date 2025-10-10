/*
��������ʹ�õ������ָ�룬����ɾ�������ǽ���destroy������������֮����ɾ��
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

/*ͷ�巨����������ʵ�ַ�ת������ͬ����Ҫ��һ��ͷ��㲻��������*/
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
    cout<< "�����뵥����ĳ��ȣ�";
    int len;
    cin>> len;
    elemType a[len];
    cout<< "�����뷴תǰ�ĵ�����";
    for(int i= 0; i< len; i++)
    {
        cin>> a[i];
    }
    nodeCreate(head, newhead, a, len);
    nodeReverse(head, newhead, len);
    cout<< "��ת��ĵ�����";
    nodeDisp(newhead);
}