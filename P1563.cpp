#include<bits/stdc++.h>
#include<string>
using namespace std;
struct P
{
    int dir1;
    string str;
    int id;
};

struct Order
{
    int dir2;
    int step;
};

int main()
{
    int n, m;
    cin>> n>> m;
    P a[n];
    for(int i= 0; i< n; i++)
    {
        cin>> a[i].dir1>> a[i].str;
        a[i].id= i;
    }
    Order o[m];
    for(int i= 0; i< m; i++)
    {
        cin>> o[i].dir2>> o[i].step;
    }

    int cnt= 0;
    for(int i= 0; i< m; i++)
    {
        if((a[cnt].dir1== 0 && o[i].dir2== 0) || (a[cnt].dir1== 1 && o[i].dir2== 1))
        {
            cnt= (n+ cnt- o[i].step% n)% n;
        }
        else if((a[cnt].dir1== 0 && o[i].dir2== 1) || (a[cnt].dir1== 1 && o[i].dir2== 0))
        {
            cnt= (cnt+ o[i].step% n)% n;
        }
    }

    for(int i= 0; i< n; i++)
    {
        if(cnt== a[i].id)
        {
            cout<< a[i].str;
        }
    }
}