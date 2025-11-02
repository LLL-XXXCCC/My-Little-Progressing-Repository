#include<bits/stdc++.h>
using namespace std;
double a, b, c, d;
double val(double x)
{
    return a* x* x* x+ b* x* x+ c* x+ d;
}

int main()
{
    cin>> a>> b>> c>> d;
    int num= 0;
    double x1, x2, l, r;
    for(int i= -100; i< 100; i++)
    {
        l= i, r= i+ 1;
        x1= val(l), x2= val(r);
        /*检查左端点*/
        if(x1== 0)
        {
            cout<< fixed<< setprecision(2)<< l<< " ";
            num++;
        }
        if(x1* x2< 0)
        {
            /*控制二分精度*/
            while(r- l> 0.001)
            {
                double m= (l+ r)/ 2;
                if(val(m)* val(r)<= 0)
                {
                    l= m;
                }
                else
                {
                    r= m;
                }
            }
            cout<< fixed<< setprecision(2)<< r<< " ";
            num++;
        }

        if(num== 3) {break;}
    }

    return 0;
}