#include<bits/stdc++.h>
using namespace std;
struct List
{
    int num;
    struct List *next;
}*L;

void listCreate(List *&head, int a[], int n)
{
    List *cur, *tail;
    head= new List;
    head-> num= a[0];
    tail= head;
    for(int i= 1; i< n; i++)
    {
        cur= new List;
        cur-> next= NULL;
        cur-> num= a[i];
        tail-> next= cur;
        tail= cur;
    }
    cur-> next= head;
}

void listDelete(List *&L, int m)
{
    List *p= L;
    for(int i= 1; i< m- 1; i++)
    {
        p= p-> next;
    }
    List *d= p-> next;
    cout<< d-> num<< " ";
    p-> next= d-> next;
    if(d== L)
    {
        L= L-> next;
    }
    delete d;

    /*��ؼ���һ��������ͷ����λ�õ�ɾ���ڵ����һ���ڵ�*/
    L= p-> next;
}

int main()
{
    int n, m;
    cin>> n>> m;
    int a[n];
    for(int i= 0; i< n; i++)
    {
        /*�����õ��������±�*/
        a[i]= i+ 1;
    }
    listCreate(L, a, n);
    cout<< "ɾ�����������ǣ�"<< endl;
    for(int i= 0; i< n- 1; i++)
    {
        listDelete(L, m);
    }
    cout<< endl<< "���ʣ�˵��ǣ�"<< endl;
    cout<< L-> num<< endl;
}