#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin>> n>> k;
    int a[n];
    for(int i= 0; i< n; i++)
    {
        cin>> a[i];
    }
    sort(a, a+ n);
    cout<< a[k];
}