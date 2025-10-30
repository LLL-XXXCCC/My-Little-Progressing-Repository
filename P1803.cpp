#include<bits/stdc++.h>
using namespace std;
struct Time
{
    int sta;
    int end;
};

bool cmp(Time &a, Time &b)
{
    return a.end< b.end;
}

int main()
{
    int n, cnt= 1;
    cin>> n;
    Time t[n];
    for(int i= 0; i< n; i++)
    {
        cin>> t[i].sta>> t[i].end;
    }
    sort(t, t+ n, cmp);
    int temp= t[0].end;
    for(int i= 1; i< n; i++)
    {
        if(t[i].sta>= temp)
        {
            temp= t[i].end;
            cnt++;
        }
    }
    cout<< cnt;
}