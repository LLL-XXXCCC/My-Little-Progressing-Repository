#include<bits/stdc++.h>
using namespace std;
int half(vector<int> &v, int k)
{
    int l= 0, r= v.size()- 1;
    while(l< r)
    {
        int m= l+(r- l)/ 2;
        if(v[m]>= k)
        {
            r= m;
        }
        else 
        {
            l= m+ 1;
        }
    }

    if(v[l]== k) //出来一定是l== r 
    {
        return l+ 1;
    }
    else 
    {
        return -1;
    }
}

int main()
{
    int n, m, temp1, temp2;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>> n>> m;
    vector<int> v;
    for(int i= 0; i< n; i++)
    {
        cin>> temp1;
        v.push_back(temp1);
    }
    for(int i= 1; i<= m; i++)
    {
        cin>> temp2;
        cout<< half(v, temp2)<< " ";
    }
}
