/*�������ģ��˼·��k�������������ȣ�i����ÿһ��Ľڵ���*/

#include<bits/stdc++.h>
#include<stdlib.h>
#include<cstring>
#define MAX 20
using namespace std;
int n, num= 0, res[MAX]= {0}, col[MAX]= {0};
int diag1[2* MAX]= {0};              /*���Խ��ߣ����µ�����*/
int diag2[2* MAX]= {0};              /*���Խ��ߣ����ϵ�����*/

void dfs(int dep)
{
    
    if(dep== n+ 1)
    {
        num++;
        for(int i= 1; i<= n; i++)
        {
            cout<< res[i]<< " ";
        }
        cout<< endl;
        return;
    }

    for(int i= 1; i<= n; i++)
    {
        if(col[i]== 0 && diag1[i+ dep]== 0 && diag2[dep- i+ n]== 0)
        {
            res[dep]= i;
            col[i]= 1;
            diag1[i+ dep]= 1;
            diag2[dep- i+ n]= 1;
            dfs(dep+ 1);
            col[i]= 0;
            diag1[i+ dep]= 0;
            diag2[dep- i+ n]= 0;
        }
    }
}

int main()
{
    cout<< "���������̵�ά����";
    cin>> n;
    dfs(1);
    cout<< endl;
    cout<< n<< "�ʺ�����һ����"<< num<< "�ֽⷨ"<< endl;

}