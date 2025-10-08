/*����ⲻһ���ĵط����ô���֮ǰ��Ӧ�÷�����������ֵ��С��������㣬ֵ��󲻴����յ㣬ÿ���㶼Ҫ����һ��*/

#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
int m, n;
int dirx[4]= {-1, 0, 1, 0};
int diry[4]= {0, 1, 0, -1};
int maxLen= 0;                                   /*ȫ�ֱ��������·��*/

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
    cin>> m>> n;                                 /*�ֱ���������������*/
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
            visited[i][j]= 1;                   /*���������Ϊ1*/
            dfs(i, j, graph, visited, 1);       /*ÿ���ط���dfsһ�飬�Ƚϳ����·��*/ 
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