#include<bits/stdc++.h>
using namespace std;
int cnt= 0;
vector<int> a;
void fun(int sta, int end)
{
    if(sta> end) {return ;}
    int min_val = a[sta];
    //һ���Լ�ȥ�����ⷴ������ѭ��
    for (int i = sta; i <= end; i++) 
    {
        if (a[i] < min_val) 
        {
            min_val = a[i];
        }
    }
    cnt += min_val;
    for (int i = sta; i <= end; i++) 
    {
        a[i] -= min_val;
    }
    
    /*��Ҫ����һ��һ�����ҡ����õݹ顢ɾ��*/
    for (int i = sta; i <= end; i++) 
    {
        if (a[i] == 0) 
        {
            fun(sta, i - 1);
            sta = i + 1;
        }
    }
    fun(sta, end);
}

int main()
{
    int n, temp;
    cin>> n;
    for(int i= 0; i< n; i++)
    {
        cin>> temp;
        a.push_back(temp);
    }
    fun(0, a.size()- 1);
    cout<< cnt;
}