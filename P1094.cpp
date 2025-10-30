#include<bits/stdc++.h>
using namespace std;

int main()
{
    int w, n, temp, cnt= 0;
    cin>> w>> n;
    vector<int> a;
    for(int i= 0; i< n; i++)
    {
        cin>> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end(), greater<int>());
    int p1= 0, p2= a.size()- 1;
    while(p1<= p2)
    {
        if(p1== p2) 
        {
            cnt++;
            p1++;
            p2--;
        }
        else
        {
            if(a[p1]+ a[p2]> w)
            {
                p1++;
                cnt++;
            }
            else
            {
                cnt++;
                p1++;
                p2--;
            }
        }
    }
    cout<< cnt;
}