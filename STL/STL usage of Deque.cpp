/*
deque ˫�˶��е�STL������ͷ��β����������ɾԪ��
push_back(x)    β������x
push_front(x)   ͷ������x

pop_front()     ɾ��ͷ��Ԫ��
pop_back()      ɾ��β��Ԫ��
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