/*
该题bfs核心：利用visited数组来处理一个点周围的邻节点,while保证所有邻节点都跑了一遍广搜
*/

#include<bits/stdc++.h>
#include<stdlib.h>
#define MAX 100
using namespace std;
int visited[MAX][MAX];
char graph[MAX][MAX];
int n, m;
int dirx[4]= {-1, 0, 1, 0};
int diry[4]= {0, 1, 0, -1};
queue<int> qx;
queue<int> qy;

void bfs(int x, int y)
{
    qx.push(x);
    qy.push(y);
    while(!qx.empty() && !qy.empty())
    {
        int curx= qx.front();
        int cury= qy.front();
        qx.pop(), qy.pop();
        for(int i= 0; i< 4; i++)
        {
            int nx= curx+ dirx[i];
            int ny= cury+ diry[i];
            if(nx>= 0 && nx< m && ny>= 0 && ny< n && visited[nx][ny]== 0 && graph[nx][ny]== 'L')
            {
                visited[nx][ny]= 1;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
}

int main()
{
    int cnt= 0;
    cin>> m>> n;
    for(int i= 0; i< m; i++)
    {
        for(int j= 0; j< n; j++)
        {
            cin>> graph[i][j];
            visited[i][j]= 0;
        }
    }

    for(int i= 0; i< m; i++)
    {
        for(int j= 0; j< n; j++)
        {
            if(visited[i][j]== 0)
            {
                visited[i][j]= 1;
                if(graph[i][j]== 'L')
                {
                    cnt++;
                    bfs(i, j);
                }
            }
        }
    }
    cout<< cnt<< endl;
}