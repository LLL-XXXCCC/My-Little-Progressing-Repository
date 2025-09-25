#include<bits/stdc++.h>
#include<stdlib.h>
#define MAXSIZE 100
using namespace std;
typedef char elemType;
struct Node
{
    elemType data;
    struct Node *next;
};

void nodeCreate(Node *&head, elemType a[], int n)   /*头节点不保存数据型*/
{
    head= new Node;
    Node *cur, *tail;
    tail= head;
    for(int i= 0; i< n; i++)
    {
        cur= new Node;
        cur-> data= a[i];
        cur-> next= NULL;
        /*最开始的时候，tail和head共享同一个地址，所以第一次循环的时候head下一个节点就是cur了*/
        tail-> next= cur;
        tail= cur;
    }
}

void nodeDestroy(Node *&head)
{
    Node *pre, *p;
    pre= head;
    p= pre-> next;
    while(p!= NULL)
    {
        delete []pre;
        pre= p;
        p= pre-> next;
    }
    delete []pre;
}

int nodeLen(Node *head)     /*这里计算的是保存了数据的节点长度，即没有包含头节点*/
{
    int count= 0;
    Node *p= head-> next;
    while(p!= NULL)
    {
        count++;
        p= p-> next;
    }
    return count;
}

void nodeDisp(Node *head)
{
    Node *p;
    p= head-> next;
    while(p!= NULL)
    {
        cout<< p-> data<< " ";
        p= p-> next;
    }

    cout<< endl;
}

elemType nodeGetElem(Node *head, int index)     /*物理序号*/
{
    if(index< 0 || index>= nodeLen(head))
    {
        return -1;
    }
    else
    {
        int i= 0;
        Node *p= head;
        while(i< index && p!= NULL)
        {
            i++;
            p= p-> next;
        }

        if(p== NULL)
        {
            return -1;
        }
        else
        {
            return p-> data;
        }
    }
}

void nodeInsert(Node *&head, int index, elemType value)
{
    if(index< 0 || index>= nodeLen(head))
    {
        cout<< endl<< "插入的序号不匹配！！"<< endl;
    }
    else
    {
        Node *p= head, *temp;
        temp= new Node;
        int j= 0;
        while(j< index && p!= NULL)     /*注意：这里循环条件是且，如果是或的话，p不是NULL直接跑到最后了，无法插入*/
        {
            j++;
            p= p-> next;
        }

        temp-> data= value;
        temp-> next= p-> next;
        p-> next= temp;
    }
}

void nodeDelete(Node *&head, int index)
{
    if(index< 0 || index>= nodeLen(head))
    {
        cout<< "删除的序号不匹配"<< endl;
    }
    else
    {
        Node *p= head;
        int i= 0;
        while(i< index && p!= NULL)     /*这里的问题和insert那里是一样的*/
        {
            p= p-> next;
            i++;
        }

        p-> next= p-> next-> next;
        free(p-> next);
    }
}

int main()
{
    char *arr;
    Node *head;
    arr= new char[MAXSIZE];
    for(int i= 0; i< 20; i++)
    {
        arr[i]= 'a'+ i;
    }
    nodeCreate(head, arr, 20);
    cout<< "该链表的长度为："<< nodeLen(head)<< endl;
    int index1, index2, index3;
    elemType value;

    nodeDisp(head);
    cout<< endl;
    
    cout<< "你想查询第几号数据：";
    cin>> index1;
    cout<< nodeGetElem(head, index1)<< endl;

    cout<< "你想在链表中插入第几号、插入数据的值为：";
    cin>> index2>> value;
    nodeInsert(head, index2, value);
    nodeDisp(head);

    cout<< "你想删除链表中第几号：";
    cin>> index3;
    nodeDelete(head, index3);
    nodeDisp(head);

    nodeDestroy(head);
    delete []arr;
    return 0;
}