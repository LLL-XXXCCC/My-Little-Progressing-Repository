/*
��Ҫ���Ǹ�ָ������ڴ�
*/

#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
typedef int elemType;
struct sqList
{
    elemType data[MAX];
    int len;
}*L, *newL;

void listCreate(sqList *&L, sqList*&newL, elemType a[], int n)
{
    L= new sqList;
    newL= new sqList;
    for(int i= 0; i< n; i++)
    {
        L-> data[i]= a[i];
    }
    L-> len= n;
    newL-> len= 0;
}

void listReverse(sqList *&newL, sqList *&L)
{
    for(int i= 0; i< L-> len; i++)
    {
        newL-> data[i]= L-> data[L-> len- i- 1];
    }
    newL-> len= L-> len;
}

void listDisp(sqList *x)
{
    for(int i= 0; i< x-> len; i++)
    {
        cout<< x-> data[i]<< " ";
    }
}

int main()
{
    int n;
    cout<< "������˳���ĳ��ȣ�";
    cin>> n;
    cout<< "�����뷴תǰ��˳���";
    elemType a[MAX];
    for(int i= 0; i< n; i++)
    {
        cin>> a[i];
    }
    listCreate(L, newL, a, n);    
    listReverse(newL, L);
    cout<< "��ת���˳���";
    listDisp(newL);
    delete[] L;
    delete[] newL;
}