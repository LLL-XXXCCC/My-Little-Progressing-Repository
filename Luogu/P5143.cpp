#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
struct Stu
{
    int x;
    int y;
    int z;
};

bool compare(const Stu &a, const Stu &b)
{
    return a.z< b.z;
}

int main()
{
    int n;
    cin>> n;
    Stu s[n];
    float dis= 0;
    for(int i= 0; i< n; i++)
    {
        cin>> s[i].x>> s[i].y>> s[i].z;
    }
    sort(s, s+ n, compare);
    for(int i= 1; i< n; i++)
    {
        dis+= sqrt((s[i- 1].x- s[i].x)* (s[i- 1].x- s[i].x)+ (s[i- 1].y- s[i].y)* (s[i- 1].y- s[i].y)+ (s[i- 1].z- s[i].z)* (s[i- 1].z- s[i].z));
    }
    cout<< setiosflags(ios::fixed | ios::showpoint)<< setprecision(3)<< dis<< endl;
}