/*greater<int>:С���ѣ��洢����int,������vector<int> ���൱��ÿ��push�Լ�pop��Ҫ����sort����*/
/*���Ҫ�Զ���Ƚϣ���ṹ���Ԫ�رȽϣ�����compareһ�����ڵ�����λ���Զ���compare����*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, temp;
    long long sum= 0;
    cin>> n;
    vector<int> v;
    for(int i= 0; i< n; i++)
    {
        cin>> temp;
        v.push_back(temp);
    }
    priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());//��vector��������ʼ��priority_queue
    while(pq.size()> 1)
    {
        int first= pq.top();
        pq.pop();
        int second= pq.top();
        pq.pop();
        temp= first+ second;
        sum+= temp;
        pq.push(temp);
    }
    cout<< sum;
}