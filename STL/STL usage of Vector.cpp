#include<bits/stdc++.h>
using namespace std;
int main()
{          
    int m, n, cnt= 0;  
    cout<< "�������άvector������������:";
    cin>> m>> n;

    /*������һ������Ϊn���������ݵ�ֵΪ100��һά����*/
    vector<int> a(n,100);

    /*��ά������ɱ�����*/
    vector<vector<int>> b;

    /*�����ʼ���������������Ķ�ά����*/
    vector<vector<int>> v(m, vector<int>(n));           /*m������Ϊn��һά����*/
    for(int i= 0; i< m; i++)
    {
        for(int j= 0; j< n; j++)
        {
            cnt++;
            //v.push_back(cnt);             
            //����һάvector��push_back����Ԫ�أ����ڶ�άvector��push_back����һ��һά��vector
            v[i][j]= cnt;
        }
    }

    cout<< "��ά������"<< v.size()<< "��"<< endl;
    cout<< "��ά������"<< v[0].size()<< "��"<< endl;
    v.pop_back();//ɾ�����һ��Ԫ��
    //v.insert(v.begin()+ 20, 1000);            
    //��push_backһ�������ڶ�άvector��insert����һ��һά��vector
    vector<int> newvector(v[0].size(), 1999);
    v.insert(v.begin()+ 2, newvector);

    cout<< "��ú��vector:"<< endl;
    for(int i= 0; i< v.size(); i++)
    {
        for(int j= 0; j< v[i].size(); j++)
        {
            cout<< v[i][j]<< " ";
        }
        cout<< endl;
    }
}