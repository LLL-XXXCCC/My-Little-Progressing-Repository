/*
ͻ�Ƶ㣺�ĳ��ַ���������compare�������ڱȽ�ƴ��ǰ����ַ�����С��
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool compare(const string &a, const string &b)
{
    return a+ b> b+ a;
}

int main()
{
    int n;
    cin>> n;
    vector<string> nums(n);
    for(int i= 0; i< n; i++)
    {
        cin>> nums[i];
    }

    sort(nums.begin(), nums.end(), compare);
    if(nums[0]== "0")
    {
        cout<< "0";
        return 0;
    }

    for(int i= 0; i< n; i++)
    {
        cout<< nums[i];
    }
    return 0;
}