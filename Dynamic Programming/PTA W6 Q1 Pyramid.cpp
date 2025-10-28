/*
״̬ת�Ʒ��̣�dp[i][j]= max{dp[i+ 1][j], dp[i+ 1][j+ 1]}+ a[i][j]
����һ������Ĺ���
�ֲ����Ž�==ȫ�����Ž�
*/

#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin>> n;
    vector<vector<int>> dp(n);//��������Ϊn�Ķ�άvector
    for(int i= 0; i< n; i++)
    {
        dp[i].resize(i+ 1);//�����άvector������Ϊn+ 1
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