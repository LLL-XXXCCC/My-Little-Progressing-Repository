#include<bits/stdc++.h>
#define MAXVAL 302
using namespace std;
int visited[MAXVAL][MAXVAL];
int time_used[MAXVAL][MAXVAL];
int T, ans= 0;
bool flag= 0;
int dirx[4]= {0, -1, 0, 1};
int diry[4]= {-1, 0, 1, 0};

void bfs(int x, int y)
{        
    time_used[x][y]= 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty())
    {
        int curx= q.front().first;
        int cury= q.front().second;
        q.pop();
        if(visited[curx][cury]== 1001) 
        {
            flag= 1;
            ans= time_used[curx][cury];
            return; 
        }
        for(int i= 0; i< 4; i++)
        {
            int newx= curx+ dirx[i];
            int newy= cury+ diry[i];
            if(newx>= 0 && newx< MAXVAL && newy>= 0 && newy<=MAXVAL && time_used[curx][cury]+ 1< visited[newx][newy] && time_used[newx][newy] == -1)
            {
                time_used[newx][newy]= time_used[curx][cury]+ 1;
                q.push(make_pair(newx, newy));
            }
        }
    }
}

int main()
{
    cin>> T;
    int x, y, t;
    vector<int> data_x;
    vector<int> data_y;
    vector<int> data_t;
    for(int i= 0; i< T; i++)
    {
        cin>> x>> y>> t;
        data_x.push_back(x);
        data_y.push_back(y);
        data_t.push_back(t);
    }
    for(int i= 0; i< MAXVAL; i++)
    {
        for(int j= 0; j< MAXVAL; j++)
        {
            time_used[i][j]= -1;
            visited[i][j]= 1001;
        }
    }
    for (int i = 0; i < T; i++)
    {
        x = data_x[i];
        y = data_y[i];
        t = data_t[i];
        if (t < visited[x][y])
        {
            visited[x][y] = t;
        }

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dirx[d];
            int ny = y + diry[d];
            if (nx >= 0 && nx < MAXVAL && ny >= 0 && ny < MAXVAL)
            {
                if (t < visited[nx][ny])
                {
                    visited[nx][ny] = t;
                }
            }
        }
    }
    if (visited[0][0] == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    bfs(0, 0);
    if(flag) {cout<< ans;}
    else {cout<< -1;}
    return 0;
}