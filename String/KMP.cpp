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
            /*不是很理解*/                       
        }
        else
        {
            j= next[j];
            /*不是很理解怎么回溯的*/
        }
    }
}

/*p是子串，t是目标串*/
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
            cout<< "匹配成功的位置在："<< i- j<< endl;
            j= next[j];                                 /*匹配成功也要回溯*/
            flag= 1;
        }
    }

    if(flag== 0)
    {
        cout<< "不能匹配"<< endl;
    }
}
int main()
{
    cout<< "请输入子串：";
    char p[MAXSIZE];
    gets(p);
    cout<< "请出入目标串：";
    char t[MAXSIZE];
    gets(t);
    KMP(p, t);
}