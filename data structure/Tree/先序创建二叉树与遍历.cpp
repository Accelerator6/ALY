#include <iostream>
#include <stdlib.h>
using namespace std;
typedef char TElemtype;


/*结点结构体*/
typedef struct BiTNode
{
    TElemtype date;
     BiTNode * lchild, *rchild;
}BiTNode,*BiTree;


/*创建树*/
void CreateBiTree (BiTree & T)
{
    TElemtype ch;
    cin>>ch;
    if(ch == '*')
        T = NULL;
    else
    {
        T = new BiTNode;
        T->date = ch;
        CreateBiTree(T->lchild);                 //构建左子树
        CreateBiTree(T->rchild);                 //构建右子树
    }

}

/*二叉树的先序遍历*/
void PreOrderTraverse(BiTree T)
{
    if( T == NULL)
        return ;
    cout<<T->date<<endl;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
/*二叉树的中序遍历*/
void InOrderTraverse(BiTree T)
{
    if( T == NULL)
        return ;
    PreOrderTraverse(T->lchild);
    cout<<T->date<<endl;
    PreOrderTraverse(T->rchild);
}
/*二叉树的后序遍历*/
void PostOrderTraverse(BiTree T)
{
    if( T == NULL)
        return ;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    cout<<T->date<<endl;
}
int main()
{
    BiTree T;
    cout<<"开始创建二叉树"<<endl;
    CreateBiTree(T);
    cout<<"二叉树创建完毕"<<endl;
    cout<<"先序遍历:"<<endl;
    PreOrderTraverse(T);
    cout<<"中序遍历:"<<endl;
    InOrderTraverse(T);
    cout<<"后序遍历:"<<endl;
    PostOrderTraverse(T);
    return 0;
}
