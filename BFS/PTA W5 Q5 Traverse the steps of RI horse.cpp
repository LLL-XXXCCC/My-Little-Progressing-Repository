#include<bits/stdc++.h>
#include<iomanip>
#include<stdlib.h>
#define MAX 400
using namespace std;
int m, n, sx, sy;
int graph[MAX][MAX], visited[MAX][MAX];
int dirx[8]= {-1, 1, 2, 2, 1, -1, -2, -2};
int diry[8]= {2, 2, 1, -1, -2, -2, -1, 1};
queue<int> qx;
queue<int> qy;

void bfs(int x, int y)
{
    qx.push(x);
    qy.push(y);
    while(!qx.empty() && !qy.empty())
    {
        /*cnt++       这里有问题：cnt代表的是访问的节点的总数（理解一下）*/
        int curx= qx.front();
        int cury= qy.front();
        qx.pop(), qy.pop();
        for(int i= 0; i< 8; i++)
        {
            int newx= curx+ dirx[i];
            int newy= cury+ diry[i];
            if(newx>= 0 && newx< m && newy>= 0 && newy< n && visited[newx][newy]== 0)
            {
                visited[newx][newy]= 1;
                graph[newx][newy]= graph[curx][cury]+ 1;        /*总这里代表迭代层数*/
                qx.push(newx);
                qy.push(newy);
            }
        }
    }
}

int main()
{
    cin>> m>> n>> sx>> sy;
    for(int i= 0; i< m; i++)
    {
        for(int j= 0; j< n; j++)
        {
            visited[i][j]= 0;
            graph[i][j]= -1;
        }
    }
    visited[sx- 1][sy- 1]= 1;
    graph[sx- 1][sy- 1]= 0;
    bfs(sx- 1, sy- 1);
    for(int i= 0; i< m; i++)
    {
        for(int j= 0; j< n; j++)
        {
            cout<<setw(5)<< graph[i][j]<< " ";
        }
        cout<< endl<< endl;
    }
}