#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct Time
{
    int start;
    int end;
};

bool compare(Time &a, Time &b)
{
    return a.end< b.end;
}

int main()
{
    int n;
    cin>> n;
    Time t[n];
    for(int i= 0; i< n; i++)
    {
        cin>> t[i].start>> t[i].end;
    }
    sort(t, t+ n, compare);

    int temp= t[0].end, cnt= 1;
    for(int i= 1; i< n; i++)
    {
        if(t[i].start> temp)
        {
            cnt++;
            temp= t[i].end;
        }
    }
    cout<< cnt;
}