/*
�����ϣ��ĺ���˼·��ͳ�ƽ���+ ����
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
        mp[a[i]]++;//����ͳ��B���ִ����Ĺ�ϣ��
    }
    for(int i= 0; i< N; i++)
    {
        ans+= mp[a[i]+ C];
    }
    cout<< ans<< endl;
}