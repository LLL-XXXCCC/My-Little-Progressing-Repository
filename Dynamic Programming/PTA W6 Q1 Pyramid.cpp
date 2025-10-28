/*
状态转移方程：dp[i][j]= max{dp[i+ 1][j], dp[i+ 1][j+ 1]}+ a[i][j]
且是一种逆序的过程
局部最优解==全局最优解
*/

#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin>> n;
    vector<vector<int>> dp(n);//定义行数为n的二维vector
    for(int i= 0; i< n; i++)
    {
        dp[i].resize(i+ 1);//定义二维vector的列数为n+ 1
        for(int j= 0; j<= i; j++)
        {
            cin>> dp[i][j];
        }
    }
    for(int i= n- 2; i>= 0; i--)
    {
        for(int j= 0; j<= i; j++)
        {
            dp[i][j]+= max(dp[i+ 1][j+ 1], dp[i+ 1][j]);
        }
    }
    cout<< dp[0][0];
}