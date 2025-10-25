/*
总结经验：BFS时间复杂度较高，如果能直接得到数学公式将会是最快的：排列组合
所以以后优先考虑时间复杂度最低的情况
*/

/*#include<bits/stdc++.h>
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
}*/

#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
    long long n, m;
    cin>> n>> m;
    long long s, t, minval;
    minval= (n< m)? n: m;
    s= (minval *(minval + 1)* (2* minval + 1))/ 6+ (minval* (minval + 1)* abs(n- m))/ 2;
    t= (n* (n+ 1)/ 2)* (m* (m+ 1)/ 2)- s;
    cout<< s<< " "<< t;
}