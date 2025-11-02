#include<bits/stdc++.h>
#define MAX 14
using namespace std;
int n, ans= 0;
int a[3][MAX];
int col[MAX]= {0}, res[MAX], diag1[2*MAX]= {0}, diag2[2*MAX]= {0};
void dfs(int dep)
{
    if(dep== n+ 1)
    {
        ans++;
        if(ans<= 3)
        {
            for(int i= 1; i<= n; i++)
            {
                a[ans- 1][i- 1]= res[i];//保证数组不会越界
            }
        }
        return ;
    }

    for(int i= 1; i<= n; i++)
    {
        if(col[i]== 0 && diag1[dep+ i]== 0 && diag2[n- i+ dep]== 0)
        {
            res[dep]= i;
            col[i]= 1;
            diag1[dep+ i]= 1;
            diag2[n- i+ dep]= 1;
            dfs(dep+ 1);
            col[i]= 0;
            diag1[dep+ i]= 0;
            diag2[n- i+ dep]= 0;
        }
    }
}

int main()
{
    cin>> n;
    dfs(1);
    for(int i= 0; i< 3; i++)
    {
        for(int j= 0; j< n; j++)
        {
            cout<< a[i][j]<< " ";
        }
        cout<< endl;
    }
    cout<< ans;
}