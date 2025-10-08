/*这个题不一样的地方（敲代码之前就应该分析出来）：值最小不代表起点，值最大不代表终点，每个点都要遍历一遍*/

#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
int m, n;
int dirx[4]= {-1, 0, 1, 0};
int diry[4]= {0, 1, 0, -1};
int maxLen= 0;                                   /*全局变量储存最长路径*/

void dfs(int x ,int y, int **graph, int **visited, int curLen)
{
    if(curLen> maxLen)
    {
        maxLen= curLen;
    }

    for(int i= 0; i< 4; i++)
    {
        int newx= x+ dirx[i];
        int newy= y+ diry[i];
        if(newx>= 0 && newx< m && newy>= 0 && newy< n && graph[newx][newy]> graph[x][y] && visited[newx][newy]== 0)
        {
            visited[newx][newy]= 1;
            dfs(newx, newy, graph, visited, curLen+ 1);
            visited[newx][newy]= 0;
        }
    }
}

int main()
{
    cin>> m>> n;                                 /*分别输入行数和列数*/
    int **visited= new int*[m];           
    for(int i= 0; i< m; i++)
    {
        visited[i]= new int[n];
        for(int j= 0; j< n; j++)
        {
            visited[i][j]= 0;
        }
    }

    int **graph= new int*[m];           
    for(int i= 0; i< m; i++)
    {
        graph[i]= new int[n];
        for(int j= 0; j< n; j++)
        {
            cin>> graph[i][j];
        }
    }

    for(int i= 0; i< m; i++)
    {
        for(int j= 0; j< n; j++)
        {
            visited[i][j]= 1;                   /*将起点设置为1*/
            dfs(i, j, graph, visited, 1);       /*每个地方都dfs一遍，比较出最长的路径*/ 
            visited[i][j]= 0;
        }
    }
    cout<< maxLen<< endl;

    for(int i= 0; i< m; i++)
    {
        delete[] visited[i];
        delete[] graph[i];
    }
    delete[] visited;
    delete[] graph;
}