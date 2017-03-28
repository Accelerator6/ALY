#include<stdio.h>
#include<stdlib.h>
#define MaxSize 99

struct
{
             char data[MaxSize];
             int top;                  /*topΪջ��*/
}op;                             /*����һ����data��top�Ľṹ��*/

void translate(char str[],char exp[])   /*���������ʽת���ɺ�׺���ʽ*/
{

      char ch;
      int i = 0,t = 0;
      op.top = -1;
      ch = str[i];                       /*��str��ÿһ����ת����ch*/
      i++;
      while(ch != '\0')                  /*ch��Ӧ��ͬ�ķ��ŵ�ʱ���Ӧ��ת�����*/
      {
             switch(ch)
             {
             case '(':                 /*���ǣ���ʱ�򣬽������Ŵ���ջop*/
                    op.top++;op.data[op.top]=ch;
                    break;
             case ')':
                    while(op.data[op.top] != '(')     /*�����ڵ�ת�����ȼ���ߣ�������ȡ���ʽ*/
                    {
                           exp[t]=op.data[op.top];
                           op.top--;
                           t++;
                    }
                    op.top--;
                    break;
             case '+':
             case '-':
                    while(op.top != -1&&op.data[op.top] != '(')
                    {
                           exp[t] = op.data[op.top];
                           op.top--;
                           t++;
                    }
                    op.top++;            /*�ָ��ɲ���λ��*/
                    op.data[op.top] = ch;
                    break;
             case '*':
             case '/':
                    while(op.top == '/'||op.top == '*')       /*���ȼ�*/
                    {
                           exp[t] = op.data[op.top];
                           op.top--;
                           t++;
                    }
                    op.top++;
                    op.data[op.top] = ch;
                    break;
             case ' ':                         /*���Կո��ų������*/
                    break;
             default:
                    while(ch >= '0'&&ch <= '9')
                    {
                           exp[t] = ch;t++;
                           ch = str[i];i++;
                    }
                    i--;
                    exp[t] = ' ';              /*�ָ���������Ϊ�����ۣ�ҲΪ���Ժ�÷ָ����������Ǻ�*/
                    t++;
             }
             ch = str[i];
             i++;
      }
      while(op.top != -1)                   /*�õ�ʣ�µĲ���*/
      {
             exp[t] = op.data[op.top];
             t++;
             op.top--;
      }
      exp[t] = '\0';                         /*���ʽ����*/
}
float cal_value(char exp[])
{
      struct
      {
             float data[MaxSize];
             int top;
      }st;                                /*������ջ*/
      float d;
      char ch;
      int t = 0;
      st.top = -1;
      ch = exp[t];
      t++;
      while(ch != '\0')
      {
             switch(ch)                  /*��������*/
             {
              case '+':
                     st.data[st.top-1] = st.data[st.top-1]+st.data[st.top];
                     st.top--;
                     break;
              case '-':
                     st.data[st.top-1] = st.data[st.top-1]-st.data[st.top];
                     st.top--;
                     break;
              case '*':
                     st.data[st.top-1] = st.data[st.top-1]*st.data[st.top];
                     st.top--;
                     break;
              case '/':
                      if(st.data[st.top] != 0)
                             st.data[st.top-1]=st.data[st.top-1]/st.data[st.top];
                      else
                      {
                             printf("\n\t��0�Ǵ����");
                      }
                      st.top--;
                      break;
              default:
                     d=0;
                     while(ch >= '0'&&ch <= '9')       /*�Ӻ�׺���ʽ�л�ȡ��������#�����ڴ�����*/
                     {
                            d = 10*d+ch-'0';
                            ch = exp[t];
                            t++;
                     }
                     st.top++;
                     st.data[st.top] = d;
           }
           ch = exp[t];
           t++;
      }
      return st.data[st.top];
}
int main()                                   /*�����ᵽǰ��ȥ*/
{
      char str[MaxSize],exp[MaxSize];       /*strΪ�������ʽ,expsΪ��׺���ʽ*/
      printf("������һ����ֵ���ʽ\n");
      printf("���ʽ:");
      gets(str);                            /*����һ���������ʽ*/
      printf("ԭ���ʽ��:%s\n",str);
      translate(str,exp);                   /*���������ʽת���ɺ�׷���ʽ*/
      printf("��׺���ʽ��%s\n",exp);
      printf("������:%g\n",cal_value(exp));/*ͨ����׺���ʽ����ֵ*/
      system("pause");
      return 0;

}
