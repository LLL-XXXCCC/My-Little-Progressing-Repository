#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define MAX 6
char graph[MAX][MAX];
int visited[MAX][MAX];
int m, n, len, flag= 0;
char str[100];
int dirx[4]= {-1, 0, 1, 0};
int diry[4]= {0, 1, 0, -1};

void dfs(int x, int y, int step)
{
    if(step== len)
    {
        flag= 1;
        return;
    }

    for(int i= 0; i< 4; i++)
    {
        int nx= x+ dirx[i];
        int ny= y+ diry[i];
        if(nx>= 0 && nx< m && ny>= 0 && ny< n && visited[nx][ny]== 0 && graph[nx][ny]== str[step])
        {
            visited[nx][ny]= 1;
            dfs(nx, ny, step+ 1);
            visited[nx][ny]= 0;
        }
    }
}

int main()
{
    cin>> m>> n;
    for(int i= 0; i< m; i++)
    {
        for(int j= 0; j< n; j++)
        {
            cin>> graph[i][j];
            visited[i][j]= 0;
        }
    }

    cin>> str;
    len= strlen(str);
    for(int i= 0; i< m; i++)
    {
        for(int j= 0; j< n; j++)
        {
            if(graph[i][j]== str[0])
            {
                visited[i][j]= 1;
                dfs(i, j, 1);
                visited[i][j]= 0;
            }
        }
    }
    if(flag== 0) {cout<< "FALSE"<< endl;}
    else {cout<< "TRUE"<< endl;}
}