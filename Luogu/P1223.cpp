#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct Peo
{
    int t;
    int id;
};

bool cm(Peo &a, Peo &b)
{
    if(a.t!= b.t)
    {
        return a.t< b.t;
    }
    else
    {
        return a.id< b.id;
    }
}

int main()
{
    int n;
    double sum= 0;
    cin>> n;
    Peo a[n];
    for(int i= 0; i< n; i++)
    {
        cin>> a[i].t;
        a[i].id= i+ 1;
    }

    sort(a, a+ n, cm);
    for(int i= 0; i< n- 1; i++)
    {
        cout<< a[i].id<< " ";
        sum+= (n- 1- i)* a[i].t;
    }
    sum= sum/ n;
    cout<< a[n- 1].id<< endl<< setiosflags(ios::fixed | ios::showpoint)<< setprecision(2)<< sum<< endl;
}