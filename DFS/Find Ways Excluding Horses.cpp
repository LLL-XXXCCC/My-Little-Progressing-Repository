#include<bits/stdc++.h>
#define MAX 30
using namespace std;
int dirx[2]= {0, 1};
int diry[2]= {1, 0};
int n, m, hx, hy;
long long cnt= 0;
vector<vector<int>> visited;

void horse(vector<vector<int>> &visited)
{
    int dx[8]= {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8]= {-2, -1, 1, 2, 2, 1, -1, -2};
    for(int i= 0; i< 8; i++)
    {
        int nx= hx+ dx[i];
        int ny= hy+ dy[i];
        if(nx>= 0 && nx<= n && ny>= 0 && ny<= m)
        {
            visited[nx][ny]= 1;
        }
    }
    visited[hx][hy]= 1;
}

void dfs(int x, int y)
{
    if(x== n && y== m) 
    {
        cnt++;
        return;
    }

    for(int i= 0; i< 2; i++)
    {
        int nx= x+ dirx[i];
        int ny= y+ diry[i];
        if(nx>= 0 && nx<= n && ny>= 0 && ny<= m && visited[nx][ny]== 0)
        {
            visited[nx][ny]= 1;
            dfs(nx, ny);
            visited[nx][ny]= 0;
        }
    }
}

int main()
{
    cin>> n>> m>> hx>> hy;
    cout<< "¼ÆËãÖÐ"<< endl;
    visited.resize(n+ 1, vector<int>(m+ 1, 0));
    horse(visited);
    visited[0][0]= 1;
    dfs(0, 0);
    cout<< cnt;
}