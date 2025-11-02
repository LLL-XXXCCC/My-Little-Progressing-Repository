/*
二分答案：check函数+二分
应用题思想：模拟而不是去真的被题目误导去改变（我愚蠢的思维总是想先去改变vector，这样会非常的复杂）
 
思考：简单的语言包含复杂的含义，而不是像翻译一样一句一句的顺序表达出来
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 50010
int a[MAX];
int len, m, n;

bool check(int x)
{
    int pos= 0, removed= 0;
    for(int i= 0; i< n+ 1; i++)
    {
        /*本体最关键的地方：如果他们的实际距离小于二分距离，那么就应该移走，否则就不移走条件就是移走的个数*/
        if(a[i]- pos< x)
        {
            removed++;
        }
        else
        {
            pos= a[i];
        }
    }
    if(removed<= m)
    {
        return true ;//二分太大
    }
    else
    {
        return false;//二分太小
    }
}

int main()
{
    cin>> len>> n>> m;
    for(int i= 0; i< n; i++)
    {
        cin>> a[i];
    }
    a[n]= len;
    int l= 0, r= len, ans;
    while(l<= r)
    {
        int m= (l+ r)/ 2;
        if(check(m)) {ans= m, l= m+ 1;}
        else {r= m- 1;}
    }
    cout<< ans;
}