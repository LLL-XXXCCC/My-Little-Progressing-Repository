#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string, string> dict;
    dict.insert(make_pair("left", "排序"));
    dict.insert(make_pair("right","排序"));
    dict.insert(make_pair("aaa", "王总"));
    cout<< "map会按key的字典序升序排列"<< endl;
    for(auto i: dict)
    {
        cout<< i.first<< ":"<< i.second<< endl;
    }

    cout<< "find函数：find函数找到的话会返回元素的迭代器，否则返回end的迭代器:"<< endl;
    auto pos= dict.find("left");
    if(pos!= dict.end())
    {
        cout<< "找到了"<< endl;
        cout<< pos-> first<< ":"<< pos-> second<< endl;
    }



    /*
    lower_bound 和 upper_bound用于二分查找，返回一个迭代器，分别指向第一个大于等于 和 大于key的第一个元素 
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