#include<bits/stdc++.h>
#define MAX 6
using namespace std;
int n, m, t, sx, sy, ex, ey;
bool visited[MAX][MAX];
int cnt= 0;
int dirx[4]= {0, -1, 0, 1};
int diry[4]= {-1, 0, 1, 0};

void dfs(int x, int y)
{
    if(x== ex- 1 && y== ey- 1)
    {
        cnt++;
        return;
    }

    for(int i= 0; i< 4; i++)
    {
        int nx= x+ dirx[i];
        int ny= y+ diry[i];
        if(nx>= 0 && nx< m && ny>= 0 && ny< n && visited[nx][ny]== 0)
        {
            visited[nx][ny]= 1;
            dfs(nx, ny);
            visited[nx][ny]= 0;
        }
    }
}

int main()
{
    cin>> n>> m>> t;
    cin>> sx>> sy>> ex>> ey;
    for(int i= 0; i< m; i++)
    {
        for(int j= 0; j< n; j++)
        {
            visited[i][j]= 0;
        }
    }
    int tx, ty;
    for(int i= 0; i< t; i++)
    {
        cin>> tx>> ty;
        visited[tx- 1][ty- 1]= 1;
    }
    visited[sx- 1][sy- 1]= 1;
    dfs(sx- 1, sy- 1);
    cout<< cnt;
}