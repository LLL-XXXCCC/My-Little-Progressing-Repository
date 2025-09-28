#include<bits/stdc++.h>
#include<string>
#define MAXSIZE 2000
using namespace std;
void getNext(char *p, int *next)
{
    int i= 0, j= -1, len= strlen(p);
    next[0]= -1;
    while(i< len)
    {
        if(j== -1 || p[i]== p[j])
        {
            i++;
            j++;
            next[i]= j;  
            /*���Ǻ����*/                       
        }
        else
        {
            j= next[j];
            /*���Ǻ������ô���ݵ�*/
        }
    }
}

/*p���Ӵ���t��Ŀ�괮*/
void KMP(char *p, char *t)
{
    bool flag= 0;
    int lenp= strlen(p), lent= strlen(t), i= 0, j= 0;
    int next[MAXSIZE];
    getNext(p, next);
    while(i< lent && j< lenp)
    {
        if(j== -1 || t[i]== p[j])
        {
            i++;
            j++;
        }
        else
        {
            j= next[j];
        }

        if(j== lenp)
        {
            cout<< "ƥ��ɹ���λ���ڣ�"<< i- j<< endl;
            j= next[j];                                 /*ƥ��ɹ�ҲҪ����*/
            flag= 1;
        }
    }

    if(flag== 0)
    {
        cout<< "����ƥ��"<< endl;
    }
}
int main()
{
    cout<< "�������Ӵ���";
    char p[MAXSIZE];
    gets(p);
    cout<< "�����Ŀ�괮��";
    char t[MAXSIZE];
    gets(t);
    KMP(p, t);
}