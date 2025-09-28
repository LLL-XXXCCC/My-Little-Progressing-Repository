#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
int dirx[4]= {1, 0, -1, 0};                  /*��������*/
int diry[4]= {0, 1, 0, -1};
int goal_x, goal_y, start_x, start_y;    
int row, col;
int step_x[1000][1000], step_y[1000][1000];

void dfs(int x, int y, int &count, char **visited)
{
    /*����˼·�����ж��Ƿ񵽴�Ŀ��ص㣬�ٽ��е����Լ�����*/
    if(x== goal_x && y== goal_y)
    {
        count++;
        return ;
    }

    for(int i= 0; i< 4; i++)
    {
        int new_x= x+ dirx[i];
        int new_y= y+ diry[i];
        if(new_x>= 0 && new_x< row && new_y>= 0 && new_y< col && visited[new_x][new_y]== '0')
        {
            visited[new_x][new_y]= '1';
            dfs(new_x, new_y, count, visited);    
            visited[new_x][new_y]= '0';                             /*���ݲ���*/   
        }
    }

}

void Initial(int m, int n, char **visited, int &goal_x, int &goal_y, int &start_x, int &start_y)
{
    for(int i= 0; i< m; i++)
    {
        for(int j= 0; j< n; j++)
        {
            cin>> visited[i][j];
            if(visited[i][j]== 'S') 
            {
                start_x= i; 
                start_y= j; 
                visited[i][j]= '0';
            }
            else if(visited[i][j]== 'E') 
            {
                goal_x= i; 
                goal_y= j;
                visited[i][j]= '0';
            }
        }
    }
}

int main()
{
    int count= 0;

    cout<< "��ȷ������Ĺ�ģ"<< endl;
    cout<< "����Ϊ��";
    cin>> row;
    cout<< "����Ϊ��";
    cin>> col;
    cout<< "�������Թ�:"<< endl;
    char **visited= new char*[row];           
    for(int i= 0; i< row; i++)
    {
        visited[i]= new char[col];
    }

    Initial(row, col, visited, goal_x, goal_y, start_x, start_y);
    visited[start_x][start_y]= '1';
    dfs(start_x, start_y, count, visited);
    cout<< "һ���У�"<< count<< "��·��"<< endl;

    for(int i= 0; i< row; i++)
    {
        delete []visited[i];
    }
    delete []visited;
}
