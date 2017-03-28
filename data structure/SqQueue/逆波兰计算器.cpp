#include <iostream>
#include <string.h>
using namespace std;
#define MAXSIZE 100
typedef char ElemType;

/*
 *          一个简单的线性栈（删除，增添，遍历）
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
/*I为原来字符数组中的索引 T为后缀字符数组中的索引（不含括号）*/
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
					cout<<"被除数不能为0！"<<endl;
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
    cout<<"请输入表达式：";
    cin>>str;
    translate(str,sdd);
    cout<<"逆波兰表达式为："<<sdd<<endl;
    cout<<"结果为:"<<complet(sdd);
}
