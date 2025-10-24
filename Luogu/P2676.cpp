#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    int n, h;
    cin>> n>> h;
    int a[n];
    for(int i= 0; i< n; i++)
    {
        cin>> a[i];
    }
    sort(a, a+ n, greater<int>());
    int sum= 0, j= 0;
    while(1)
    {
        sum+= a[j];
        j++;
        if(sum>= h)
        {
            cout<< j;
            break;
        }
    }
}