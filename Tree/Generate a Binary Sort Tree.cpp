/*
生成二叉树：左子树节点小于根节点，右子树节点大于根节点
*/

#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
typedef int elemType;
struct BT
{
    BT *lchild, *rchild;
    elemType data;
};

int Insert(BT *&tree, elemType k)
{
    if(tree== NULL)
    {
        tree= new BT;
        tree-> data= k;
        tree-> lchild= NULL, tree-> rchild= NULL;
        return 1;
    }
    else
    {
        if(tree-> data== k)
        {
            cout<< "生成二叉树有重复的元素！"<< endl;
            return 0;
        }
        else if(k< tree-> data)
        {
            return Insert(tree-> lchild, k);
        }
        else
        {
            return Insert(tree-> rchild, k);
        }
    }
}
   
void levelOrder(BT *b)
{
    queue<BT *> q;
    q.push(b);
    int size;
    while(!q.empty())
    {
        size= q.size();     //隐式转换
        for(int i= 0; i< size; i++)
        {
            if(q.front()-> lchild!= NULL)
            {
                q.push(q.front()-> lchild);
            }
            if(q.front()-> rchild!= NULL)
            {
                q.push(q.front()-> rchild);
            }
            cout<< q.front()-> data<< "   ";
            q.pop();
        }
        cout<< endl;
    }
}

int main()
{
    BT *tree= NULL;
    int n;
    elemType a[10000];
    cout<< "生成二叉树的节点个数：";
    cin>> n;
    cout<< "需要排序的数值：";
    for(int i= 0; i< n; i++)
    {
        cin>> a[i];
    }

    for(int i= 0; i< n; i++)
    {
        Insert(tree, a[i]);
    }
    levelOrder(tree);
}

