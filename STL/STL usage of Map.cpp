#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string, string> dict;
    dict.insert(make_pair("left", "����"));
    dict.insert(make_pair("right","����"));
    dict.insert(make_pair("aaa", "����"));
    cout<< "map�ᰴkey���ֵ�����������"<< endl;
    for(auto i: dict)
    {
        cout<< i.first<< ":"<< i.second<< endl;
    }

    cout<< "find������find�����ҵ��Ļ��᷵��Ԫ�صĵ����������򷵻�end�ĵ�����:"<< endl;
    auto pos= dict.find("left");
    if(pos!= dict.end())
    {
        cout<< "�ҵ���"<< endl;
        cout<< pos-> first<< ":"<< pos-> second<< endl;
    }



    /*
    lower_bound �� upper_bound���ڶ��ֲ��ң�����һ�����������ֱ�ָ���һ�����ڵ��� �� ����key�ĵ�һ��Ԫ�� 
    */

    map<int, string> mp;
    mp.insert(make_pair(1, "one"));
    mp.insert(make_pair(3, "three"));
    mp.insert(make_pair(5, "five"));
    mp.insert(make_pair(7, "seven"));
    mp.insert(make_pair(9, "nine"));
    auto lb= mp.lower_bound(5);
    if(lb!= mp.end())
    {
        cout<< "lower_bound(5) "<< lb-> first<< ":"<< lb-> second<< endl;
    }
    auto ub= mp.upper_bound(5);
    if(ub!= mp.end())
    {
        cout<< "upper_bound(5) "<< ub-> first<< ":"<< ub-> second<< endl;
    }
}