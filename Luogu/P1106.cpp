/*
֮ǰ������������洢Ϊvector<char>���Ҷ�ÿ��Ԫ�ؽ�������
�������˼��ɾ������k�����֡���
ʣ�µ����ְ�ԭ������С����
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