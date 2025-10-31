/*
之前错误的做法：存储为vector<char>并且对每个元素进行排序
本题的意思是删除任意k个数字——
剩下的数字按原次序最小！！
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a;
    string str;
    cin>> str;
    for(int i= 0; i< str.size(); i++) {a.push_back(str[i]- '0');}
    int k, cntzero= 0;
    cin>> k;
    for(int i= 0; i< k; i++)
    {
        int j= 0;
        while(j< a.size()- 1 && a[j]<= a[j+ 1]) {j++;}
        a.erase(a.begin()+ j);
    }
    for(int i= 0; i< a.size(); i++)
    {
        if(a[i]== 0) {cntzero++;}
    }
    if(cntzero== a.size()) {cout<< 0;}
    else if(a[0]== 0)
    {
        for(int i= cntzero; i< a.size(); i++) {cout<< a[i];}
    }
    else
    {
        for(int i= 0; i< a.size(); i++) {cout<< a[i];}
    }
}