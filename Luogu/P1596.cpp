#include<bits/stdc++.h>
#define MAX 101
using namespace std;
bool visited[MAX][MAX];
char graph[MAX][MAX];
int n, m, cnt= 0;
int dirx[8]= {0, -1, 0, 1, -1, -1, 1, 1};
int diry[8]= {-1, 0, 1, 0, -1, 1, 1, -1};

void bfs(int x, int y)
{
    cnt++;
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
            if(nx>= 0 && nx< n && ny>= 0 && ny< m && visited[nx][ny]== 0 && graph[nx][ny]== 'W')
            {
                q.push(make_pair(nx, ny));
                visited[nx][ny]= 1;
            }
        }
    }
}

int main()
{
    cin>> n>> m;
    for(int i= 0; i< n; i++)
    {
        for(int j= 0; j< m; j++)
        {
            cin>> graph[i][j];
            visited[i][j]= 0;
        }
    }

    for(int i= 0; i< n; i++)
    {
        for(int j= 0; j< m; j++)
        {
            if(visited[i][j]== 0 && graph[i][j]== 'W')
            {
                bfs(i, j);
            }
        }
    }
    cout<< cnt;
}