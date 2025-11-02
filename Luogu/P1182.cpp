/*
关键点：要把等号放在判断可行解是否为最值那里
*/

#include<bits/stdc++.h>
int n, m;
int a[100005];
using namespace std;

bool check(int x)
{
    int tot= 0, size= 1;
    for(int i= 0; i< n; i++)
    {
        if(a[i]> x) {return true;}
        tot+= a[i];
        if(tot> x)
        {
            size++;
            tot= a[i];
        }

        if(size> m) {break;}
    }
    if(size> m)
    {
        return true;
    }
    else//size多了，说明最大值还可以更小，至少是可行解，正在求可行解的最小值是多少
    {
        return false;
    }
}

int main()
{
    cin>> n>> m;
    int max= 0;
    for(int i= 0; i< n; i++)
    {
        cin>> a[i];
        if(max< a[i]) {max= a[i];}
    }
    int l= max, r= 1000000001, ans;
    while(l<= r)
    {
        int mid= (l+ r)/ 2;
        if(check(mid))
        {
            l= mid+ 1;
        }
        else
        {
            ans= mid;
            r= mid- 1;
        }
    }
    cout<< ans;
}