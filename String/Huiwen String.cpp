#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<char> dq;
    char ch;
    bool flag= 1;
    while((ch= getchar())!= '\n')
    {
        dq.push_front(ch);
    }

    while(1)
    {
        if(dq.size()== 0)
        {
            break;
        }
        else if(dq.size()== 1)
        {
            break;
        }
        if(dq.front()!= dq.back()) {flag= 0;}
        dq.pop_front();
        dq.pop_back();
    }
    if(flag== 0) {cout<< "字符串不是回文数";}
    else {cout<< "字符串是回文数";}
}