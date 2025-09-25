#include<bits/stdc++.h>
#include<malloc.h>
#define MAXSIZE 100
using namespace std;
typedef char elemType;
typedef struct
{
    elemType data[MAXSIZE];
    int len;    /*������*/
}sqList;

void listCreate(sqList *&L, char a[], int n)    /*!!���ô��ݣ��������յ�����ָ������ã������ڲ���ָ����޸Ķ���Ӱ�쵽ԭʼ��ָ��*/
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
        cout<< "�ñ�Ϊ�ձ�"<< endl;
    }
    for(int i= 0; i< L-> len; i++)
    {
        cout<< "��"<< i+ 1<< "��Ԫ���ǣ�"<< L-> data[i]<< endl;
    }
}

elemType listGetElem(sqList *L, int index)
{
    if(listEmpty(L)== 1)
    {
        cout<< "�ñ�Ϊ�ձ�"<< endl;
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
        cout<< "�����������"<< endl;
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
    cout<< "��������������ĳ��ȣ�";
    cin>> n;
    cout<< "�����������ѯ����ţ�";
    cin>> index;
    cout<< "����������������ź����ݣ�";
    cin>> index1>> value1;
    elemType *a;
    a= new elemType[n];
    for(int i= 0; i< n; i++)
    {
        a[i]= 'a'+ i;
    }
    listInitial(L);
    listCreate(L, a, n);
    if(listEmpty(L)== 1) {cout<< "������Ϊ��";}
    else {cout<< "������Ϊ��"<< endl;}
    len= listLength(L);
    cout<< "List�ĳ����ǣ�"<< len<< endl;
    value= listGetElem(L, index);
    cout<< "��Ŷ�Ӧ�������ǣ�"<< value<< endl;
    listInsert(L, index1, value1);
    listDisp(L);
    delete []a;
}