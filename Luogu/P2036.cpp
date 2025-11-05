#include<bits/stdc++.h>
using namespace std;
int n;

int mul(vector<int> com_s)
{
    int res= 1;
    for(int i= 0; i< com_s.size(); i++)
    {
        res*= com_s[i];
    }
    return res;
}

int add(vector<int> com_b)
{
    int res= 0;
    for(int i= 0; i< com_b.size(); i++)
    {
        res+= com_b[i];
    }
    return res;
}

void combine(vector<pair<int, int>> &a, vector<int> &res, vector<int> com_s, vector<int> com_b, int start, int limit)
{
    if(com_b.size()== limit && com_s.size()== limit)
    {
        res.push_back(abs(mul(com_s)- add(com_b)));
        return;
    }

    for(int i= start; i< n; i++)
    {
        com_s.push_back(a[i].first);
        com_b.push_back(a[i].second);
        combine(a, res, com_s, com_b, i+ 1, limit);
        com_s.pop_back();
        com_b.pop_back();
    }
}

int main()
{
    cin>> n;
    int t1, t2;
    vector<pair<int, int>> a;
    vector<int> res, com_s, com_b;
    for(int i= 0; i< n; i++)
    {
        cin>> t1>> t2;
        a.push_back(make_pair(t1, t2));
    }
    for(int i= 1; i<= n; i++)
    {
        combine(a, res, com_s, com_b, 0, i);
    }

    sort(res.begin(), res.end());
    cout<< res[0];
}