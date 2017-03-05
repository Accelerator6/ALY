#include <iostream>
#define Status int
#define MAXSIZE 50
using namespace std;
typedef struct      //  储存一个线性表
{
    ElemType elem[MAXSIZE];
    int length;
}SqList;

Status InitList(SqList& L)
{
    L.length = 0;
}

void ListTraverse(SqList L)
{
	int i;
	cout<<'(';
	for(i=1;i<=L.length;i++)
		cout<<L.elem[i-1]<<',';
	if(L.length) cout<<"\b)"<<endl;
	else cout<<')'<<endl;
}


Status CreateList(SqList &L,int n)
{
	int i;
	if(!L.elem||n<0||n>MAXSIZE) return ERROR;
	cout<<"\n请输入"<<n<<"个元素：";
	for(i=1;i<=n;i++)
		cin>>L.elem[i-1];     //可以用随机函数rand()自动生成
	L.length=n;
	return OK;
}


Status ListLength(SqList& L)
{
    return L.length;
}

Status GetElem(SqList& L,int i,ElemType& e)
{
    i--;
    if(i<0||i>L.length-1)
        return ERROR;
    e=L.elem[i];
}

Status LocateElem(SqList& L,ElemType& e)
{
    for(int i=0;i<L.length;i++)
    {
        if(e==L.elem[i])
            return ++i;
    }
    return ERROR;
}

Status ListInsert(SqList& L,int i,ElemType& e)
{
    if(L.length==MAXSIZE)
        return ERROR;
    if(i<1||i>L.length+1)
        return ERROR;
    if(i<=L.length)
    {
        for(int k=L.length-1;k>=i-1;k--)
            L.elem[k+1]=L.elem[k];
    }
    L.elem[i-1]=e;
    L.length++;
    return OK;
}

Status ListDelete(SqList& L,int i,ElemType& e)
{
    if(L.length==0)
        return ERROR;
    if(i<1||i>L.length)
        return ERROR;
    i--;
    e=L.elem[i];
    if(i<L.length-1)
    {
        for(int k=L.length-1;k>=i;k--)
            L.elem[k]=L.elem[k+1];
    }
    L.length--;
    return OK;

}
