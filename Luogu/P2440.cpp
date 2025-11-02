/*
使用二分的关键词：最小sth.的最大
在满足target的情况下，要求得到一根圆木的最大值，
由题目，l是0，r是100000001，然后不断二分，复杂度是log2n
记住二分的判断标准：l+ 1< r, 这样二分最后出来l= r
*/

#include<bits/stdc++.h>
#define MAX 100000000
using namespace std;
vector<int> a;
int n, k;

bool check(int x)
{
    int ans= 0;
    for(int i= 0; i< n; i++)
    {
        ans+= a[i]/ x;
    }
    if(ans< k) {return 0;}
    else {return 1;}
}

int main()
{
    int temp;
    cin>> n>> k;
    for(int i= 0; i< n; i++)
    {
        cin>> temp;
        a.push_back(temp);
    }

    int l= 0, r= MAX+ 1, ans;
    while(l<= r)
    {
        int m= (r+ l)/ 2;
        if(check(m)) {ans= m, l= m+ 1;}
        else {r= m- 1;}
    }
    cout<< ans;
    return 0;
}