#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct Trea
{
    int m;
    int v;
    float val;
};

bool cmp(Trea &a, Trea &b)
{
    return a.val> b.val;
}

int main()
{
    int N, T;
    cin>> N>> T;
    Trea t[N];
    for(int i= 0; i< N; i++)
    {
        cin>> t[i].m>> t[i].v;
        t[i].val= t[i].v* 1.0 / t[i].m;
    }

    sort(t, t+ N, cmp);
    float sumVal= 0;
    int sumM= 0;
    for(int i= 0; i< N; i++)
    {
        if(sumM+ t[i].m<= T)
        {
            sumM+= t[i].m;
            sumVal+= t[i].v;
        }
        else
        {
            sumVal+= (T- sumM)* 1.0 *t[i].v/ t[i].m;
            break;
        }
    }
    cout<< setiosflags(ios::fixed |ios:: showpoint)<< setprecision(2)<< sumVal<< endl;
}