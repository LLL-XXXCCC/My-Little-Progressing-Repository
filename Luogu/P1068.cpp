#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct Stu
{
    int id;
    int score;
};

bool compare(const Stu &a, const Stu &b)
{
    if(a.score!= b.score)
    {
        return a.score> b.score;
    }
    return a.id< b.id;
}

int main()
{
    int n, m;
    cin>> n>> m;
    Stu s[n];
    for(int i= 0; i< n; i++)
    {
        cin>> s[i].id>> s[i].score;
    }
    sort(s, s+ n, compare);
    int k= (int) (m* 1.5);
    while(s[k- 1].score== s[k].score)
    {
        k++;
    }        
    cout<< s[k- 1].score<< " "<< k<< endl;
    for(int i= 0; i< k; i++)
    {
        cout<< s[i].id<< " "<< s[i].score<< endl;
    }
}