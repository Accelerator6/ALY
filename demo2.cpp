#include <iostream>
#include "status.h"
typedef int ElemType;
#include "LinkList.h"
using namespace std;


int main()
{
    int n;
    LinkList L1,L2,L3;
    InitList(L1);       //��������ͷ
    InitList(L2);
    InitList(L3);
    cout<<"�������һ������������Ԫ�صĸ���:";
    cin>>n;
    CreateList(L1,n);
    ListTraverse(L1);
    cout<<"\n������ڶ�������������Ԫ�صĸ���:";
    cin>>n;
    CreateList(L2,n);
    ListTraverse(L2);
    cout<<"��������ϲ�:"<<endl;
    if(ADD(L1,L2,L3))
    {
        cout<<"�ϲ��ɹ�!"<<endl;
        ListTraverse(L3);
    }
    else
        cout<<"ERROR!"<<endl;
    return 0;
}
