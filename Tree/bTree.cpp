/*
括号法建立二叉树：
（：代表左子树开始，操作为k= 1, 根节点进栈
，：代表右子树开始，操作为k= 2
）：代表左右子树都处理完毕，操作为根节点退栈
节点值：开辟p根节点，判断存放到左节点还是右节点
*/

#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct BT
{
    char data;
    struct BT *lchild, *rchild;
}*bTree;

void btCreate(BT *&b, char *str)
{
    stack<BT *> s;          //栈用于存放指针
    BT *p;
    b= NULL;
    int k, j= 0;
    char ch= str[j];
    while(ch!= '\0')
    {
        switch(ch)
        {
            case '(': k= 1, s.push(p); break;
            case ',': k= 2; break;
            case ')': s.pop(); break;
            default:
                p= new BT;
                p-> data= ch;
                p-> lchild= p-> rchild= NULL;
                if(b== NULL)
                {
                    b= p;
                }
                else
                {
                    BT *parent= s.top();
                    if(k== 1)
                    {
                        parent-> lchild= p;
                    }
                    else
                    {
                        parent-> rchild= p;
                    }
                }
        }
        j++;
        ch= str[j];
    }
}

void btDestroy(BT *&b)
{
    if(b== NULL)
    {
        return;
    }
    else
    {
        btDestroy(b-> lchild);
        btDestroy(b-> rchild);
        delete[] b;
    }
}

int btDepth(BT *b)
{
    int ld, rd;
    if(b== NULL)
    {
        return (0);
    }
    else
    {
        ld= btDepth(b-> lchild);
        rd= btDepth(b-> rchild);
        return(ld> rd)? (ld+ 1): (rd+ 1);
    }
}

void btDisp(BT *b)
{
    if(b!= NULL)
    {
        cout<< b-> data;
        if(b-> lchild!= NULL || b-> rchild!= NULL)
        {
            cout<< "(";
            btDisp(b-> lchild);
            if(b-> rchild!= NULL)
            {
                cout<< ",";
            }
            btDisp(b-> rchild);
            cout<< ")";
        }
    }
}

int main()
{
    cout<< "请输入括号法表示的二叉树：";
    char str[100];
    cin>> str;
    btCreate(bTree, str);
    cout<< "二叉树的深度是："<< btDepth(bTree)<< endl;
    btDisp(bTree);
    btDestroy(bTree);
}