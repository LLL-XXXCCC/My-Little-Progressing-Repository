#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int dirx[8]= {-1, 0, 1, 0, -1, 1, 1, -1};
int diry[8]= {0, 1, 0, -1, 1, 1, -1, -1};
int n, m;
char a[MAX][MAX];

void search(int x, int y)
{
    int cnt= 0;
    for(int i= 0; i< 8; i++)
    {
        int nx= x+ dirx[i];
        int ny= y+ diry[i];
        if(a[x][y]== '?' && nx>= 0 && nx< n && ny>= 0 && ny< m && a[nx][ny]== '*')
        {
            cnt++;
        }
    }
    cout<< cnt;
}

int main()
{
    cin>> n>> m;
    for(int i= 0; i< n; i++)
    {
        for(int j= 0; j< m; j++)
        {
            cin>> a[i][j];
        }
    }

    for(int i= 0; i< n; i++)
    {
        for(int j= 0; j< m; j++)
        {
            if(a[i][j]== '*') {cout<< "*";}
            else {search(i, j);}
        }
        cout<< endl;
    }
}