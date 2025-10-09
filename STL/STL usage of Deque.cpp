/*
deque 双端队列的STL操作，头部尾部都可以增删元素
push_back(x)    尾部插入x
push_front(x)   头部插入x

pop_front()     删除头部元素
pop_back()      删除尾部元素
*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> dq;
    dq.push_back(100);
    for(int i= 0; i< 10; i++)
    {
        dq.push_front(i);
    }
    cout<< dq[3]<< endl;
    dq.pop_back();
    dq.pop_front();
    for(int i= 0; i< dq.size(); i++)
    {
        cout<< dq[i]<< " ";
    }
}