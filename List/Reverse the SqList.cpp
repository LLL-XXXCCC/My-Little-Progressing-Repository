/*
不要忘记给指针分配内存
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
    cout<< "请输入顺序表的长度：";
    cin>> n;
    cout<< "请输入反转前的顺序表：";
    elemType a[MAX];
    for(int i= 0; i< n; i++)
    {
        cin>> a[i];
    }
    listCreate(L, newL, a, n);    
    listReverse(newL, L);
    cout<< "反转后的顺序表：";
    listDisp(newL);
    delete[] L;
    delete[] newL;
}