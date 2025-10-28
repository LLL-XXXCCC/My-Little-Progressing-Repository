#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>> n;
    int x, y;
    x= n/ 5;
    n%= 5;
    y= n/ 2;
    n%= 2;
    cout<< x+ y+ n;
}