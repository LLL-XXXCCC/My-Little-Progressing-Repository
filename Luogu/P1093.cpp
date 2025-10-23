#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct Stu
{
    int id;
    int score[3];
    int sum;
};

bool compare(const Stu &a, const Stu &b)
{
    if(a.sum!= b.sum)
    {
        return a.sum> b.sum;
    }
    if(a.score[0]!= b.score[0])
    {
        return a.score[0]> b.score[0];
    }
    return a.id< b.id;
}

int main()
{
    int n;
    cin>> n;
    Stu s[n];
    for(int i= 0; i< n; i++)
    {
        cin>> s[i].score[0]>> s[i].score[1]>> s[i].score[2];
        s[i].id= i+ 1;
        s[i].sum= s[i].score[0]+ s[i].score[1]+ s[i].score[2];
    }  

    sort(s, s+ n, compare);
    for(int i= 0; i< 5; i++)
    {
        cout<< s[i].id<< " "<<s[i].sum << endl;
    }
}