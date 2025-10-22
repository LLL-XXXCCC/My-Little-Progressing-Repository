#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    int n, temp;
    cin>> n;
    vector<int> a;
    for(int i= 0; i< n; i++)
    {
        cin>> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    for(unsigned int i= 0; i< a.size()- 1; )
    /*一位erase不断减小容器的大小，所以边界不能设置为n儿时a.size()*/
    {
        if(a[i]== a[i+ 1])
        {
            a.erase(a.begin()+ 1+ i);
        }
        else
        {
            i++;
        }
    }

    cout<< a.size()<< endl;
    for(unsigned int i= 0; i< a.size(); i++)
    {
        cout<< a[i]<< " ";
    }
}