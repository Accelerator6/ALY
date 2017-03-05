#include <iostream>
using namespace std;
#include "Status.h"
typedef int ElemType;
#include "LinkList.h" //用#include "LinkList.h"替换

int main()
{
	LinkList L;              //用LinkList L;替换，与#include "LinkList.h"配合
	int n,i;
	ElemType e;
	InitList(L);
	cout<<"\nL=";
	ListTraverse(L);
	cout<<"\n请设置将向线性表L中输入的元素个数：";
	cin>>n;
	CreateList(L,n);
	cout<<"\nL=";
	ListTraverse(L);
	cout<<"\nL的表长为："<<ListLength(L)<<endl;
	cout<<"\n请输入想要获取的元素位序：";
	cin>>i;
	if(GetElem(L,i,e)) cout<<"\n第"<<i<<"个元素为："<<e<<endl;
	else cout<<"\n第"<<i<<"个元素不存在！"<<endl;
	cout<<"\n请输入要查找的元素：";
	cin>>e;
	if(i=LocateElem(L,e)) cout<<"\n元素"<<e<<"的位置为："<<i<<endl;
	else cout<<"\n元素"<<e<<"不存在！"<<endl;
	cout<<"\n请输入插入位置和所插入元素：";
	cin>>i>>e;
	if(ListInsert(L,i,e))
	{
		cout<<"\nL=";
		ListTraverse(L);
	}
	else cout<<"\n插入操作失败！"<<endl;
	cout<<"\n请输入被删元素的位置：";
	cin>>i;
	if(ListDelete(L,i,e)) cout<<"\n被删元素为："<<e<<endl;
	else cout<<"\n删除操作失败！"<<endl;
	cout<<"\nL=";
	ListTraverse(L);
	return 0;
}
