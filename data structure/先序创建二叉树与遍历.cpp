#include <iostream>
#include <stdlib.h>
using namespace std;
typedef char TElemtype;


/*���ṹ��*/
typedef struct BiTNode
{
    TElemtype date;
     BiTNode * lchild, *rchild;
}BiTNode,*BiTree;


/*������*/
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
        CreateBiTree(T->lchild);                 //����������
        CreateBiTree(T->rchild);                 //����������
    }

}

/*���������������*/
void PreOrderTraverse(BiTree T)
{
    if( T == NULL)
        return ;
    cout<<T->date<<endl;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
/*���������������*/
void InOrderTraverse(BiTree T)
{
    if( T == NULL)
        return ;
    PreOrderTraverse(T->lchild);
    cout<<T->date<<endl;
    PreOrderTraverse(T->rchild);
}
/*�������ĺ������*/
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
    cout<<"��ʼ����������"<<endl;
    CreateBiTree(T);
    cout<<"�������������"<<endl;
    cout<<"�������:"<<endl;
    PreOrderTraverse(T);
    cout<<"�������:"<<endl;
    InOrderTraverse(T);
    cout<<"�������:"<<endl;
    PostOrderTraverse(T);
    return 0;
}
