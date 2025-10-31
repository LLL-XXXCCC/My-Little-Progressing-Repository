/*greater<int>:小根堆，存储数据int,容器是vector<int> ，相当于每次push以及pop都要进行sort排序*/
/*如果要自定义比较（如结构体的元素比较），跟compare一样，在第三个位置自定义compare函数*/

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
    priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());//用vector容器来初始化priority_queue
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