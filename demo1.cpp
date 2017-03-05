#include <iostream>
using namespace std;
#include "Status.h"
typedef int ElemType;
#include "LinkList.h" //��#include "LinkList.h"�滻

int main()
{
	LinkList L;              //��LinkList L;�滻����#include "LinkList.h"���
	int n,i;
	ElemType e;
	InitList(L);
	cout<<"\nL=";
	ListTraverse(L);
	cout<<"\n�����ý������Ա�L�������Ԫ�ظ�����";
	cin>>n;
	CreateList(L,n);
	cout<<"\nL=";
	ListTraverse(L);
	cout<<"\nL�ı�Ϊ��"<<ListLength(L)<<endl;
	cout<<"\n��������Ҫ��ȡ��Ԫ��λ��";
	cin>>i;
	if(GetElem(L,i,e)) cout<<"\n��"<<i<<"��Ԫ��Ϊ��"<<e<<endl;
	else cout<<"\n��"<<i<<"��Ԫ�ز����ڣ�"<<endl;
	cout<<"\n������Ҫ���ҵ�Ԫ�أ�";
	cin>>e;
	if(i=LocateElem(L,e)) cout<<"\nԪ��"<<e<<"��λ��Ϊ��"<<i<<endl;
	else cout<<"\nԪ��"<<e<<"�����ڣ�"<<endl;
	cout<<"\n���������λ�ú�������Ԫ�أ�";
	cin>>i>>e;
	if(ListInsert(L,i,e))
	{
		cout<<"\nL=";
		ListTraverse(L);
	}
	else cout<<"\n�������ʧ�ܣ�"<<endl;
	cout<<"\n�����뱻ɾԪ�ص�λ�ã�";
	cin>>i;
	if(ListDelete(L,i,e)) cout<<"\n��ɾԪ��Ϊ��"<<e<<endl;
	else cout<<"\nɾ������ʧ�ܣ�"<<endl;
	cout<<"\nL=";
	ListTraverse(L);
	return 0;
}
