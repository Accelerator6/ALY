#include <iostream>
#define Status int
using namespace std;
typedef struct LNode     //  储存一个线性表
{
    ElemType elem;
    struct LNode  * next;
}LNode,*LinkList;

Status InitList(LinkList& L)
{
    L= new LNode;
    L->next=NULL;
    return OK;
}

Status ListTraverse(LinkList L)
{
    L=L->next;
     while(L!=NULL)
    {
        cout<< L->elem  <<" ";
        L=L->next;
    }
}


Status CreateList(LinkList L,int n)
{
	LinkList p,q;
	q = L;
	if(n<0)return ERROR;
	while(q->next)
        q=q->next;
	cout<<"\n请输入"<<n<<"个元素：";
	while(n--)
    {
        p = new LNode;
        cin>>p->elem;
        q->next=p;
        p->next=NULL;
        q=q->next;
    }
}


Status ListLength(LinkList L)
{
    int sum=0;
    L=L->next;
    while(L->next)
    {
        sum++;
        L=L->next;
    }
    sum++;
    return sum;
}

Status GetElem(LinkList L,int i,ElemType& e)
{
    L=L->next;
    while(L&&i)
    {
        i--;
        if(i==0)
        {
            e=L->elem;
            return OK;
        }
        L=L->next;
    }
    if(i!=0)
        return ERROR;
}

Status LocateElem(LinkList L,ElemType& e)
{
    int j = 0;
    while(L)
    {

        if(e==L->elem)
            return j;
        L=L->next;
        j++;
    }
    if(j==0)
        return ERROR;
}

Status ListInsert(LinkList& L,int i,ElemType& e)
{
    int j;
    LinkList p,s;
    p=L;
    j=1;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
        return ERROR;
    s=new LNode;
    s->elem=e;
    s->next=p->next;
    p->next=s;
}

Status ListDelete(LinkList& L,int i,ElemType& e)
{
   int j=1;
   LinkList p,s;
   p=L;
   while(p->next&&j<i)
   {
       p=p->next;
       ++j;
   }
   if(!(p->next)||j>i)
    return ERROR;
    s=p->next;
    p->next=s->next;
    e=s->elem;
    delete(s);
    return OK;
}

Status ADD(LinkList&L1,LinkList&L2,LinkList&L3)
{
    LinkList p1,p2,p3;
    p1=L1->next;
    p2=L2->next;
    L3=p3=L1;
    while(p1&&p2)
    {
        if(p1->elem<=p2->elem)
        {
            p3->next=p1;
            p3=p1;
            p1=p1->next;
        }
        else
        {
            p3->next=p2;
            p3=p2;
            p2=p2->next;
        }
    }

     //判断那一段还有剩余
        p3->next=(p1?p1:p2);
        delete L2;
    return OK;
}
