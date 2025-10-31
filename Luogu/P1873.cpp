#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tar;
    ll sum= 0, res;
    cin>> n>> tar;
    int a[n];
    for(int i= 0; i< n; i++)
    {
        cin>> a[i];
    }
    sort(a, a+ n, greater<int>());
    for(int i= 0; i< n- 1; i++)
    {
        sum+= a[i];
        res= (sum- tar)/ (i+ 1);
        if(res>= a[i+ 1])
        {
            cout<< res;
            break;
        }
    }
}