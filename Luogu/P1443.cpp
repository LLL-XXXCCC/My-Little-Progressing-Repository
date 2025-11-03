#include<bits/stdc++.h>
#define MAX 400
using namespace std;
int n, m, sx, sy;
int graph[MAX][MAX], visited[MAX][MAX];
int dirx[8]= {-1, -2, -2, -1, 1, 2, 2, 1};
int diry[8]= {-2, -1, 1, 2, 2, 1, -1, -2};

void bfs(int x, int y)
{
    visited[x][y]= 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty())
    {  
        int curx= q.front().first;
        int cury= q.front().second;
        q.pop();
        for(int i= 0; i< 8; i++)
        {
            int nx= curx+ dirx[i];
            int ny= cury+ diry[i];
            if(nx>= 0 && nx< n && ny>= 0 && ny< m && visited[nx][ny]== 0)
            {
                q.push(make_pair(nx, ny));
                visited[nx][ny]= 1;
                graph[nx][ny]= graph[curx][cury]+ 1;
            }
        }
    }
}

int main()
{
    cin>> n>> m>> sx>> sy;
    for(int i= 0; i< n; i++)
    {
        for(int j= 0; j< m; j++)
        {
            visited[i][j]= 0;
            graph[i][j]= -1;
        }
    }
    graph[sx- 1][sy- 1]= 0;
    bfs(sx- 1, sy- 1);
    for(int i= 0; i< n; i++)
    {
        for(int j= 0; j< m; j++)
        {
            cout<< graph[i][j]<< " ";
        }
        cout<< endl;
    }
}