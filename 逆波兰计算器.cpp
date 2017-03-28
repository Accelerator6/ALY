#include <iostream>
#include <string.h>
using namespace std;
#define MAXSIZE 100
typedef char ElemType;

/*
 *          һ���򵥵�����ջ��ɾ��������������
 */
class SqStack
{
public:
    SqStack();
    int push(ElemType e);
    int pop(ElemType & e);
    int show();
    ElemType date[MAXSIZE];
    int top;
};
SqStack::SqStack()
{
    top = -1;
}

int SqStack::push(ElemType e)
{
    if(top>99)
        return 0;
    top++;
    date[top] = e;
    return 1;
}
int SqStack::pop(ElemType & e)
{
    if(top>-1)
    {
        e = date[top];
        top--;
    }
        return 1;
}

int SqStack::show()
{
    int i = 0;
    for(i=0;i<=top;i++)
        cout<<date[i]<<" ";
}

void translate(string& a,char sdd[])
{
/*IΪԭ���ַ������е����� TΪ��׺�ַ������е��������������ţ�*/
    char ch,e;
    int i = 0,t = 0;
    SqStack Q;

    ch = a[0];
    i++;
    while(ch != '\0')
    {

		switch(ch)
        {
        case '(':
               Q.push(ch);
               i++;
               break;
        case ')':
                while(Q.date[Q.top]!='(')
                {
                    Q.pop(e);
                    sdd[t] = e;
                    t++;
                }
                Q.pop(e);
                break;
        case '+':
        case '-':
            while(Q.date[Q.top] != '('&&Q.top != -1 )
            {
                Q.pop(e);
                sdd[t] = e;
                t++;
            }

			Q.push(ch);
            break;
        case '*':
        case '/':
            while(Q.date[Q.top] =='/'||Q.date[Q.top] == '*')
            {
                Q.pop(e);
                sdd[t] = e;
                t++;
            }
            Q.push(ch);
        case ' ':break;
        default:
            while(ch >= '0'&&ch <= '9')
            {
				sdd[t++] = ch;
                ch = a[i++];
            }
            i--;
            sdd[t] = ' ';
            t++;
        }
        ch = a[i];
        i++;
    }
    while(Q.top !=-1)
    {
        Q.pop(e);
        sdd[t] = e;
        t++;
    }
    sdd[t] = '\0';
}

float complet(char sdd[])
{
	typedef  float ElemType;
	char ch;
	float sum = 0;
	int t = 0;
	SqStack Q;
	ch = sdd[t++];
	while(ch != '\0')
	{
		switch(ch)
		{
			case '+':
				Q.date[Q.top-1]=Q.date[Q.top-1]+Q.date[Q.top];
				Q.top--;
				break;
			case '-':
				Q.date[Q.top-1]=Q.date[Q.top-1]-Q.date[Q.top];
				Q.top--;
				break;
			case '*':
					Q.date[Q.top-1]=Q.date[Q.top-1]*Q.date[Q.top];
				Q.top--;
				break;
			case '/':
				if(Q.date[Q.top]==0)
				{
					cout<<"����������Ϊ0��"<<endl;
					return 0;
				}
				else
				{
						Q.date[Q.top-1]=Q.date[Q.top-1]/Q.date[Q.top];
						Q.top--;
						break;
				}
			default:
				sum = 0;
				while(ch >= '0'&& ch <= '9')
				{
					sum =sum*10+ch-'0';
					ch = sdd[t++];
				}
				Q.push(sum);
				break;
		}
		ch = sdd[t++];
	}
	return Q.date[Q.top];
}
int main()
{
    string str;
	char sdd[MAXSIZE];
    cout<<"��������ʽ��";
    cin>>str;
    translate(str,sdd);
    cout<<"�沨�����ʽΪ��"<<sdd<<endl;
    cout<<"���Ϊ:"<<complet(sdd);
}
