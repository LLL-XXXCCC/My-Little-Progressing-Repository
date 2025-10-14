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
}*bTree, *t;

/*括号法创建*/
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

/*深度*/
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


/*先序 中序 后序遍历*/
void preOrder(BT *b)
{
    if(b!= NULL)
    {
        cout<< b-> data<< " ";
        preOrder(b-> lchild);
        preOrder(b-> rchild);
    }
}

void medOrder(BT *b)
{
    if(b!= NULL)
    {
        medOrder(b-> lchild);
        cout<< b-> data<< " ";
        medOrder(b-> rchild);
    }
}

void postOrder(BT *b)
{
    if(b!= NULL)
    {
        postOrder(b-> lchild);
        postOrder(b-> rchild);
        cout<< b-> data<< " ";
    }
}

/*层次遍历*/    
void levelOrder(BT *b)
{
    queue<BT *> q;
    q.push(b);
    while(!q.empty())
    {
        if(q.front()-> lchild!= NULL)
        {
            q.push(q.front()-> lchild);
        }
        if(q.front()-> rchild!= NULL)
        {
            q.push(q.front()-> rchild);
        }
        cout<< q.front()-> data<< " ";
        q.pop();
    }
    cout<< endl;
}

/*计算节点总数以及根节点的个数*/
int nodesCounting(BT *b)
{
    if(b== NULL)
    {
        return 0;
    }
    else
    {
        return nodesCounting(b-> lchild)+ nodesCounting(b-> rchild)+ 1;
    }
}

int leafnodeCounting(BT *b)
{
    int num1= 0, num2= 0;
    if(b== NULL)
    {
        return 0;
    }
    else if(b-> lchild== NULL && b-> rchild== NULL)
    {
        return 1;
    }
    else
    {
        num1= leafnodeCounting(b-> lchild);
        num2= leafnodeCounting(b-> rchild);
        return num1+ num2;
    }
}

/*交换二叉树的左子树和右子树*/
void exchangeTree(BT *b, BT *&t)
{
    if(b== NULL) {t= NULL;}
    else
    {
        t= new BT;
        t-> data= b-> data;
        exchangeTree(b-> lchild, t-> rchild);
        exchangeTree(b-> rchild, t-> lchild);
    }
}

/*返回某一个元素所在二二叉树中的层次*/
int levelLocate(BT* b, char val, int level)
{
    if(b== NULL)
    {
        return -1;
    }
    else if(b-> data== val)
    {
        return level;
    }
    else
    {
        int left;
        left= levelLocate(b-> lchild, val, level+ 1);
        if(left== -1)
        {
            return levelLocate(b-> rchild, val, level+ 1);
        }
        else
        {
            return left;
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

    cout<< "先序遍历:";
    preOrder(bTree);
    cout<< endl;
    cout<< "中序遍历:";
    medOrder(bTree);
    cout<< endl;
    cout<< "后序遍历:";
    postOrder(bTree);
    cout<< endl;
    levelOrder(bTree);

    cout<< "节点总数："<< nodesCounting(bTree)<< endl;
    cout<< "叶子节点数："<< leafnodeCounting(bTree)<< endl;
    btDestroy(bTree);

    cout<< "输入想要查询的二叉树元素：";
    char val;
    cin>> val;
    cout<< "该元素所在的层数为："<< levelLocate(bTree, val, 1)<< endl;
}

/*
A(B(D,E),C(F,G))
*/