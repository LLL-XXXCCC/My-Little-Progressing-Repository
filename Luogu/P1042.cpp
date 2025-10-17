/*气笑了， / 和 % 别忘了*/

#include<bits/stdc++.h>
#include<math.h>
#define MAX 100000
using namespace std;

char str[MAX];
int main()
{
    int cnt= 0;
    char ch;
    while((ch= getchar())!= 'E')
    {
        if(ch== '\n') {continue;}
        str[cnt]= ch;
        cnt++;
    }

    int w= 0, l= 0;
    for(int i= 0; i< cnt; i++)
    {
        if(str[i]== 'W') {w++;}
        else if(str[i]== 'L') {l++;}
        if((l>= 11 || w>= 11) && abs(l- w)>= 2)
        {
            cout<< w<< ":"<< l<< endl;        
            w= 0, l= 0;
        }
    }
    cout<< w<< ":"<< l<< endl;
    w= 0, l= 0;
    cout<< endl;
    for(int i= 0; i< cnt; i++)
    {
        if(str[i]== 'W') {w++;}
        else if(str[i]== 'L') {l++;}
        if((l>= 21 || w>= 21) && abs(l- w)>= 2)
        {
            cout<< w<< ":"<< l<< endl;        
            w= 0, l= 0;
        }       
    } 
    cout<< w<< ":"<< l;
    w= 0, l= 0;
}