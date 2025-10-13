#include<bits/stdc++.h>
using namespace std;
int main()
{          
    int m, n, cnt= 0;  
    cout<< "请输入二维vector的行数和列数:";
    cin>> m>> n;

    /*定义了一个长度为n、所有数据的值为100的一维数组*/
    vector<int> a(n,100);

    /*二维长宽均可变数组*/
    vector<vector<int>> b;

    /*下面初始化键入行数列数的二维数组*/
    vector<vector<int>> v(m, vector<int>(n));           /*m个长度为n的一维数组*/
    for(int i= 0; i< m; i++)
    {
        for(int j= 0; j< n; j++)
        {
            cnt++;
            //v.push_back(cnt);             
            //对于一维vector，push_back的是元素；对于二维vector，push_back的是一行一维的vector
            v[i][j]= cnt;
        }
    }

    cout<< "二维数组有"<< v.size()<< "行"<< endl;
    cout<< "二维数组有"<< v[0].size()<< "列"<< endl;
    v.pop_back();//删除最后一个元素
    //v.insert(v.begin()+ 20, 1000);            
    //和push_back一样，对于二维vector，insert的是一行一维的vector
    vector<int> newvector(v[0].size(), 1999);
    v.insert(v.begin()+ 2, newvector);

    cout<< "变幻后的vector:"<< endl;
    for(int i= 0; i< v.size(); i++)
    {
        for(int j= 0; j< v[i].size(); j++)
        {
            cout<< v[i][j]<< " ";
        }
        cout<< endl;
    }
}