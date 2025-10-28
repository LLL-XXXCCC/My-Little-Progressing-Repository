#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int temp;
    while(1)
    {
        cin>> temp;
        v.push_back(temp);
        if(getchar()== '\n')
        {
            break;
        }
    }

    int cnt= 1;
    for(int i= 1; i< v.size(); i++)
    {
        if(v[i- 1]< v[i])
        {
            cnt++;
        }
    }
    cout<< cnt;
}