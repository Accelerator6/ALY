#include <iostream>
#include "status.h"
typedef int ElemType;
#include "LinkList.h"
using namespace std;


int main()
{
    int n;
    LinkList L1,L2,L3;
    InitList(L1);       //创建三个头
    InitList(L2);
    InitList(L3);
    cout<<"请输入第一条有序链表中元素的个数:";
    cin>>n;
    CreateList(L1,n);
    ListTraverse(L1);
    cout<<"\n请输入第二条有序链表中元素的个数:";
    cin>>n;
    CreateList(L2,n);
    ListTraverse(L2);
    cout<<"将两个表合并:"<<endl;
    if(ADD(L1,L2,L3))
    {
        cout<<"合并成功!"<<endl;
        ListTraverse(L3);
    }
    else
        cout<<"ERROR!"<<endl;
    return 0;
}
