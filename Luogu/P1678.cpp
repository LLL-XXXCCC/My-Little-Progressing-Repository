/*
lower_bound（a, a+ n, x)指向第一个大于等于x的迭代器
说白了就是a[多少多少]大于等于x
不是x大于等于a[i]
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, m;
    ll sum= 0;
    cin>> n>> m;
    int a[n], b[m];
    for(int i= 0; i< n; i++)
    {
        cin>> a[i];
    }
    for(int j= 0; j< m; j++)
    {
        cin>> b[j];
    }
    sort(a, a+ n);
    for(int j= 0; j< m; j++)
    {
        auto lb= lower_bound(a, a+ n, b[j]);//指针
        if(lb== a)
        {
            sum+= abs(b[j]- a[0]);
        }
        else if(lb== a+ n)
        {
            sum+= abs(b[j]- a[n- 1]);
        }
        else
        {
            int delta1= abs(*lb- b[j]);
            int delta2= abs(*(lb- 1)- b[j]);
            sum+= min(delta1, delta2);
        }
    }
    cout<< sum;
}