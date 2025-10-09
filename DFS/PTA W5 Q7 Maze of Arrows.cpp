/*验证多组数据，全局变量需要重置*/

#include<bits/stdc++.h>
#include<stdlib.h>
#include<string>
using namespace std;
#define MAX 200000
int n, flag= 0, t;
int dirx[4]= {-1, 0, 1, 0};
int diry[4]= {0, 1, 0, -1};
int visited[2][MAX];
char graph[2][MAX];
int ex= 1, ey;

void dfs(int x, int y)
{
    if(x== ex && y== ey)
    {
        flag= 1;
        return;
    }

    for(int i= 0; i< 4; i++)
    {
        int nx1= x+ dirx[i];
        int ny1= y+ diry[i];
        if(nx1>= 0 && nx1< 2 && ny1>= 0 && ny1< n && visited[nx1][ny1]== 0)
        {
            visited[nx1][ny1]= 1;
            int ny2= ny1+ (graph[nx1][ny1]== '>'? 1 : -1);
            int nx2= nx1;
            if(ny2>= 0 && ny2< n && nx2>= 0 && nx2< 2 && visited[nx2][ny2]== 0)
            {
                visited[nx2][ny2]= 1;
                dfs(nx2, ny2);
                visited[nx2][ny2]= 0;
            }
            visited[nx1][ny1]= 0;
        }
    }
}

int main()
{
    cin>> t;
    string str[t];
    for(int i= 0; i< t; i++)
    {
        cin>> n;
        for(int i= 0; i< 2; i++)
        {
            for(int j= 0; j< n; j++)
            {
                cin>> graph[i][j];
                visited[i][j]= 0;
            }
        }
        visited[0][0]= 1;
        ey= n- 1;
        dfs(0, 0);
        if(flag== 1)
        {
            str[i]= "YES";
        }
        else
        {
            str[i]= "NO";
        }
        flag= 0;

    }
    for(int i= 0; i< t; i++)
    {
        cout<< str[i]<< endl;
    }
}