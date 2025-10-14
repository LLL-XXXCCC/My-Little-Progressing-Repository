/*
���ŷ�������������
����������������ʼ������Ϊk= 1, ���ڵ��ջ
����������������ʼ������Ϊk= 2
������������������������ϣ�����Ϊ���ڵ���ջ
�ڵ�ֵ������p���ڵ㣬�жϴ�ŵ���ڵ㻹���ҽڵ�
*/

#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct BT
{
    char data;
    struct BT *lchild, *rchild;
}*bTree, *t;

/*���ŷ�����*/
void btCreate(BT *&b, char *str)
{
    stack<BT *> s;          //ջ���ڴ��ָ��
    BT *p;
    b= NULL;
    int k, j= 0;
    char ch= str[j];
    while(ch!= '\0')
    {
        switch(ch)
        {
            case '(': k= 1, s.push(p); break;
            case ',': k= 2; break;
            case ')': s.pop(); break;
            default:
                p= new BT;
                p-> data= ch;
                p-> lchild= p-> rchild= NULL;
                if(b== NULL)
                {
                    b= p;
                }
                else
                {
                    BT *parent= s.top();
                    if(k== 1)
                    {
                        parent-> lchild= p;
                    }
                    else
                    {
                        parent-> rchild= p;
                    }
                }
        }
        j++;
        ch= str[j];
    }
}

void btDestroy(BT *&b)
{
    if(b== NULL)
    {
        return;
    }
    else
    {
        btDestroy(b-> lchild);
        btDestroy(b-> rchild);
        delete[] b;
    }
}

/*���*/
int btDepth(BT *b)
{
    int ld, rd;
    if(b== NULL)
    {
        return (0);
    }
    else
    {
        ld= btDepth(b-> lchild);
        rd= btDepth(b-> rchild);
        return(ld> rd)? (ld+ 1): (rd+ 1);
    }
}

void btDisp(BT *b)
{
    if(b!= NULL)
    {
        cout<< b-> data;
        if(b-> lchild!= NULL || b-> rchild!= NULL)
        {
            cout<< "(";
            btDisp(b-> lchild);
            if(b-> rchild!= NULL)
            {
                cout<< ",";
            }
            btDisp(b-> rchild);
            cout<< ")";
        }
    }
}


/*���� ���� �������*/
void preOrder(BT *b)
{
    if(b!= NULL)
    {
        cout<< b-> data<< " ";
        preOrder(b-> lchild);
        preOrder(b-> rchild);
    }
}

void medOrder(BT *b)
{
    if(b!= NULL)
    {
        medOrder(b-> lchild);
        cout<< b-> data<< " ";
        medOrder(b-> rchild);
    }
}

void postOrder(BT *b)
{
    if(b!= NULL)
    {
        postOrder(b-> lchild);
        postOrder(b-> rchild);
        cout<< b-> data<< " ";
    }
}

/*��α���*/    
void levelOrder(BT *b)
{
    queue<BT *> q;
    q.push(b);
    while(!q.empty())
    {
        if(q.front()-> lchild!= NULL)
        {
            q.push(q.front()-> lchild);
        }
        if(q.front()-> rchild!= NULL)
        {
            q.push(q.front()-> rchild);
        }
        cout<< q.front()-> data<< " ";
        q.pop();
    }
    cout<< endl;
}

/*����ڵ������Լ����ڵ�ĸ���*/
int nodesCounting(BT *b)
{
    if(b== NULL)
    {
        return 0;
    }
    else
    {
        return nodesCounting(b-> lchild)+ nodesCounting(b-> rchild)+ 1;
    }
}

int leafnodeCounting(BT *b)
{
    int num1= 0, num2= 0;
    if(b== NULL)
    {
        return 0;
    }
    else if(b-> lchild== NULL && b-> rchild== NULL)
    {
        return 1;
    }
    else
    {
        num1= leafnodeCounting(b-> lchild);
        num2= leafnodeCounting(b-> rchild);
        return num1+ num2;
    }
}

/*��������������������������*/
void exchangeTree(BT *b, BT *&t)
{
    if(b== NULL) {t= NULL;}
    else
    {
        t= new BT;
        t-> data= b-> data;
        exchangeTree(b-> lchild, t-> rchild);
        exchangeTree(b-> rchild, t-> lchild);
    }
}

/*����ĳһ��Ԫ�����ڶ��������еĲ��*/
int levelLocate(BT* b, char val, int level)
{
    if(b== NULL)
    {
        return -1;
    }
    else if(b-> data== val)
    {
        return level;
    }
    else
    {
        int left;
        left= levelLocate(b-> lchild, val, level+ 1);
        if(left== -1)
        {
            return levelLocate(b-> rchild, val, level+ 1);
        }
        else
        {
            return left;
        }
    }
}

int main()
{
    cout<< "���������ŷ���ʾ�Ķ�������";
    char str[100];
    cin>> str;
    btCreate(bTree, str);
    cout<< "������������ǣ�"<< btDepth(bTree)<< endl;

    cout<< "�������:";
    preOrder(bTree);
    cout<< endl;
    cout<< "�������:";
    medOrder(bTree);
    cout<< endl;
    cout<< "�������:";
    postOrder(bTree);
    cout<< endl;
    levelOrder(bTree);

    cout<< "�ڵ�������"<< nodesCounting(bTree)<< endl;
    cout<< "Ҷ�ӽڵ�����"<< leafnodeCounting(bTree)<< endl;
    btDestroy(bTree);

    cout<< "������Ҫ��ѯ�Ķ�����Ԫ�أ�";
    char val;
    cin>> val;
    cout<< "��Ԫ�����ڵĲ���Ϊ��"<< levelLocate(bTree, val, 1)<< endl;
}

/*
A(B(D,E),C(F,G))
*/