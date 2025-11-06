/*
不用DFS回溯 直接对每个点进行搜索即可
*/

#include<bits/stdc++.h>
#define MAX 101
using namespace std;
int n;
bool visited[MAX][MAX];
char graph[MAX][MAX], word[7]= {'y', 'i', 'z', 'h', 'o', 'n', 'g'};
int dirx[8]= {0, -1, 0, 1, -1, -1, 1, 1};
int diry[8]= {-1, 0, 1, 0, -1, 1, 1, -1};

void search(int x, int y)
{
    for(int i= 0; i< 8; i++)
    {
        int cnt= 0;
        for(int j= 0; j< 7; j++)
        {
            int nx= x+ dirx[i]* j;
            int ny= y+ diry[i]* j;
            if(nx>= 0 && nx< n && ny>= 0 && ny< n && graph[nx][ny]== word[j])
            {
                cnt++;
            }
        }

        if(cnt== 7)//同时满足
        {
            for(int j= 0; j< 7; j++)
            {
                int nx= x+ dirx[i]* j;
                int ny= y+ diry[i]* j;
                visited[nx][ny]= 1;
            }
        }
    }
}

int main()
{
    cin>> n;
    for(int i= 0; i< n; i++)
    {
        for(int j= 0; j< n; j++)
        {
            cin>> graph[i][j];
            visited[i][j]= 0;
        }
    }

    for(int i= 0; i< n; i++)
    {
        for(int j= 0; j< n; j++)
        {
            if(graph[i][j]== 'y') {search(i, j);}//验证起点绘制visited
        }
    }

    for(int i= 0; i< n; i++)
    {
        for(int j= 0; j< n; j++)
        {
            if(visited[i][j]) {cout<< graph[i][j];}
            else {cout<< '*';}
        }
        cout<< endl;
    }
}