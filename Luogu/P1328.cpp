#include<bits/stdc++.h>
using namespace std;
int a_win_b(int a, int b)
{
    if(a== b) {return 0;}
    switch(a)
    {
        case 0: switch(b)
        {
            case 1: return -1; break;
            case 2: return 1; break;
            case 3: return 1; break;
            case 4: return -1; break;
        }
        break;

        case 1: switch(b)
        {
            case 0: return 1; break;
            case 2: return -1; break;
            case 3: return 1; break;
            case 4: return -1; break;
        }
        break;

        case 2: switch(b)
        {
            case 0: return -1; break;
            case 1: return 1; break;
            case 3: return -1; break;
            case 4: return 1; break;
        }
        break;

        case 3: switch(b)
        {
            case 0: return -1; break;
            case 1: return -1; break;
            case 2: return 1; break;
            case 4: return 1; break;
        }
        break;

        case 4: switch(b)
        {
            case 0: return 1; break;
            case 1: return 1; break;
            case 2: return -1; break;
            case 3: return -1; break;
        }
        break;
    }
}

int main()
{
    int n, na, nb;
    cin>> n>> na>> nb;
    int a[na], b[nb];
    for(int i= 0; i< na; i++)
    {
        cin>> a[i];
    }
    for(int i= 0; i< nb; i++)
    {
        cin>> b[i];
    }
    int jia, yi, cnta= 0, cntb= 0;
    for(int i= 0; i< n; i++)
    {
        jia= a[i% na];
        yi= b[i% nb];
        if(a_win_b(jia, yi)== 1)
        {
            cnta++;
        }
        else if(a_win_b(jia, yi)== -1)
        {
            cntb++;
        }
    }
    cout<< cnta<< " "<< cntb<< endl;
}