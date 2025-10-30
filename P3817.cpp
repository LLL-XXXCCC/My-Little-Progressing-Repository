#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin>> n>> x;
    long long a[n];
    for(int i= 0; i< n; i++)
    {
        cin>> a[i];
    }

    long long sum= 0, temp;
    if(a[0]> x)
    {
        temp= a[0]- x;
        sum+= temp;
        a[0]-= temp;
    }
    
    for(int i= 1; i< n; i++)
    {
        if(a[i]+ a[i- 1]> x)
        {
            temp= a[i- 1]+ a[i]- x;
            sum+= temp;
            a[i]-= temp;//????????
        }
    }
    cout<< sum;
}