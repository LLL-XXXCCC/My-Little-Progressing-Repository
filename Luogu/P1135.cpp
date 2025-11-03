#include<bits/stdc++.h>
#define MAX 205
using namespace std;
int n, a, b, ans= 0;
struct Level
{
    int dir[2];
    int dep= 0;
}step[MAX];
bool flag= 0;
bool visited[MAX]= {0};

void bfs(int l)
{
    queue<int> q;
    q.push(l);
    visited[l]= 1;
    while(!q.empty())
    {
        int curl= q.front();
        q.pop();
        for(int i= 0; i< 2; i++)
        {

            int newl= curl+ step[curl].dir[i];
            if(newl== b)
            {
                ans= step[curl].dep+ 1;
                flag= 1;
                return;
            }
            if(newl>= 0 && newl<= n && !visited[newl])
            {
                q.push(newl);
                step[newl].dep= step[curl].dep+ 1;
                visited[newl]= 1;
            }
        }
    }
}

int main()
{
    cin>> n>> a>> b;
    int temp;
    for(int i= 1; i<= n; i++)
    {
        cin>> temp;
        step[i].dir[0]= temp;
        step[i].dir[1]= -temp;
    }
    bfs(a);
    if(a== b) {ans=0;}
    if(flag) {cout<< ans;}
    else {cout<< -1;}
}