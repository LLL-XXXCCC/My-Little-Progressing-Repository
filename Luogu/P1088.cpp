#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int n, k;

int add(vector<int> &comb)
{
    int sum= 0;
    for(int i= 0; i< comb.size(); i++)
    {
        sum+= comb[i];
    }
    return sum;
}

void combine(int nums[], vector<int> &res, vector<int> &comb, int s)
{
    if(comb.size()== k)
    {
        res.push_back(add(comb));
        return;
    }

    for(int i= s; i< n; i++)
    {
        comb.push_back(nums[i]);
        combine(nums, res, comb, i+ 1);
        comb.pop_back();
    }
}

bool isPrime(int x)
{
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    
    for (int i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0) 
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin>> n>> k;
    int cnt= 0;
    int a[n];
    for(int i= 0; i< n; i++)
    {
        cin>> a[i];
    }
    vector<int> res;
    vector<int> comb;
    combine(a, res, comb, 0);
    for(int i= 0; i< res.size(); i++)
    {
        if(isPrime(res[i])) {cnt++;}
    }
    cout<< cnt;
}