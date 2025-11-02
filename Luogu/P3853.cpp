/*
如果两路灯之间的距离小于二分，说明这段距离空旷指数
如果两路灯之间的距离大于二分，说明有更长的距离，且可以安装新的路灯
*/

#include<bits/stdc++.h>
using namespace std;
int len, n, k;
int a[100005];

bool check(int d)
{
    int pos= 0, addition= 0;
    for(int i= 1; i< n; i++)
    {
        if(a[i]- pos<= d)
        {
            pos= a[i];
        }
        else if(a[i]- pos> d)
        {
            pos+= d;
            addition++;
            i--;
        }
    }
    if(addition> k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cin>> len>> n>> k;
    for(int i= 0; i< n; i++)
    {
        cin>> a[i];
    }
    int l= 0, r= len, ans;
    while(l<= r)
    {
        int m= (l+ r)/ 2;
        if(m== 0) {ans= 1; break;}
        if(check(m))
        {
            l= m+ 1;
        }
        else
        {
            ans= m;
            r= m- 1;
        }
    }
    cout<< ans;
}