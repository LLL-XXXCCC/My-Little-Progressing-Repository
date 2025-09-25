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

void nodeCreate(Node *&head, elemType a[], int n)   /*ͷ�ڵ㲻����������*/
{
    head= new Node;
    Node *cur, *tail;
    tail= head;
    for(int i= 0; i< n; i++)
    {
        cur= new Node;
        cur-> data= a[i];
        cur-> next= NULL;
        /*�ʼ��ʱ��tail��head����ͬһ����ַ�����Ե�һ��ѭ����ʱ��head��һ���ڵ����cur��*/
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

int nodeLen(Node *head)     /*���������Ǳ��������ݵĽڵ㳤�ȣ���û�а���ͷ�ڵ�*/
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

elemType nodeGetElem(Node *head, int index)     /*�������*/
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
        cout<< endl<< "�������Ų�ƥ�䣡��"<< endl;
    }
    else
    {
        Node *p= head, *temp;
        temp= new Node;
        int j= 0;
        while(j< index && p!= NULL)     /*ע�⣺����ѭ���������ң�����ǻ�Ļ���p����NULLֱ���ܵ�����ˣ��޷�����*/
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
        cout<< "ɾ������Ų�ƥ��"<< endl;
    }
    else
    {
        Node *p= head;
        int i= 0;
        while(i< index && p!= NULL)     /*����������insert������һ����*/
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
    cout<< "������ĳ���Ϊ��"<< nodeLen(head)<< endl;
    int index1, index2, index3;
    elemType value;

    nodeDisp(head);
    cout<< endl;
    
    cout<< "�����ѯ�ڼ������ݣ�";
    cin>> index1;
    cout<< nodeGetElem(head, index1)<< endl;

    cout<< "�����������в���ڼ��š��������ݵ�ֵΪ��";
    cin>> index2>> value;
    nodeInsert(head, index2, value);
    nodeDisp(head);

    cout<< "����ɾ�������еڼ��ţ�";
    cin>> index3;
    nodeDelete(head, index3);
    nodeDisp(head);

    nodeDestroy(head);
    delete []arr;
    return 0;
}