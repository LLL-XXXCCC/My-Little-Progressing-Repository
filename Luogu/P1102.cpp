/*
此题哈希表的核心思路：统计建立+ 查找
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int N;
    ll C, ans= 0;
    cin>> N>> C;
    int a[N];
    map<ll, ll> mp;
    for(int i= 0; i< N; i++)
    {
        cin>> a[i];
        mp[a[i]]++;//建立统计B出现次数的哈希表
    }
    for(int i= 0; i< N; i++)
    {
        ans+= mp[a[i]+ C];
    }
    cout<< ans<< endl;
}