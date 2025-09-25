#include<bits/stdc++.h>
#include<malloc.h>
#define MAXSIZE 100
using namespace std;
typedef char elemType;
typedef struct
{
    elemType data[MAXSIZE];
    int len;    /*物理长度*/
}sqList;

void listCreate(sqList *&L, char a[], int n)    /*!!引用传递：函数接收到的是指针的引用，函数内部对指针的修改都会影响到原始的指针*/
{
    for(int i= 0; i< n; i++)
    {
        L-> data[i]= a[i];
    }
    L-> len= n;
}

void listInitial(sqList *&L)
{
    L= new sqList;
    L-> len= 0;
}

void listDestroy(sqList *L)
{
    delete L;
}

bool listEmpty(sqList *L)
{
    if(L-> len== 0) {return true;}
    else {return false;}
}

int listLength(sqList *L)
{
    return L-> len;
}

void listDisp(sqList *L)
{
    if(listEmpty(L)== 1)
    {
        cout<< "该表为空表"<< endl;
    }
    for(int i= 0; i< L-> len; i++)
    {
        cout<< "第"<< i+ 1<< "个元素是："<< L-> data[i]<< endl;
    }
}

elemType listGetElem(sqList *L, int index)
{
    if(listEmpty(L)== 1)
    {
        cout<< "该表为空表"<< endl;
    }
    return L-> data[index- 1];
}

int listLocateElem(sqList *L, elemType value)
{
    for(int i= 0; i< L-> len; i++)
    {
        if(L-> data[i]== value)
        {
            return i+ 1;
        }
    }
    return 0;
}

void listInsert(sqList *L, int index, elemType value)
{
    if(index< 1 || index> L-> len+ 1)
    {
        cout<< "输入序号有误"<< endl;
        return;
    }
    index--;
    for(int j= L-> len; j>= index; j--)
    {
        L-> data[j]= L-> data[j- 1];
    }
    L-> data[index]= value;
    L-> len++;
}

int main()
{
    sqList *L;
    int n, len, index, index1;
    elemType value, value1;
    cout<< "请输入数据数组的长度：";
    cin>> n;
    cout<< "请输入你想查询的序号：";
    cin>> index;
    cout<< "请输入你想插入的序号和数据：";
    cin>> index1>> value1;
    elemType *a;
    a= new elemType[n];
    for(int i= 0; i< n; i++)
    {
        a[i]= 'a'+ i;
    }
    listInitial(L);
    listCreate(L, a, n);
    if(listEmpty(L)== 1) {cout<< "此链表为空";}
    else {cout<< "此链表不为空"<< endl;}
    len= listLength(L);
    cout<< "List的长度是："<< len<< endl;
    value= listGetElem(L, index);
    cout<< "序号对应的数据是："<< value<< endl;
    listInsert(L, index1, value1);
    listDisp(L);
    delete []a;
}