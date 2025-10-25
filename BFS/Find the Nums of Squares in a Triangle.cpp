#include<bits/stdc++.h>
#define MAX 5000
using namespace std;
int dirx[3]= {0, 1, 1};
int diry[3]= {1, 0, 1};
int n,m;
long long sum_Sq= 0, sum_Tr;
int visited[MAX][MAX];

void Sq(int x, int y)
{   
    visited[x][y]= 1;
    queue<pair<int, int>> q;
    /*该这样赋值*/
    q.push(make_pair(x, y));
    visited[x][y]= 1;
    long long cnt= 1, level= 1;
    while(1)
    {
        int size= q.size();
        for(int k= 0; k< size; k++)
        {
            for(int i= 0; i< 3; i++)
            {
                int nx= q.front().first+ dirx[i];
                int ny= q.front().second+ diry[i];
                if(nx>= 0 && nx< n && ny>= 0 && ny< m && visited[nx][ny]== 0)
                {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny]= 1;
                    cnt++;
                }
            }
            q.pop();
        }
        level++;

        if(cnt!= level* level || size== 0)
        {
            sum_Sq+= level- 1;
            break;
        }
    }
}

int cigema(int x)
{
    int sum= 0;
    for(int i= 1; i<= x; i++)
    {
        sum+= i;
    }
    return sum;
}

int main()
{
    cin>> n>> m;
    for(int i= 0; i< n; i++)
    {
        for(int j= 0; j< m; j++)
        {
            visited[i][j]= 0;
        }
    }

    for(int i= 0; i< n; i++)
    {
        for(int j= 0; j< m; j++)
        {
            Sq(i, j);
            for(int i= 0; i< n; i++)
            {
                for(int j= 0; j< m; j++)
                {
                    visited[i][j]= 0;
                }
            }
        }
    }
    sum_Tr= cigema(n)* cigema(m)- sum_Sq;
    cout<< sum_Sq<< " "<< sum_Tr;
}