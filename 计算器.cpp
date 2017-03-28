#include<stdio.h>
#include<stdlib.h>
#define MaxSize 99

struct
{
             char data[MaxSize];
             int top;                  /*top为栈顶*/
}op;                             /*定义一个含data和top的结构体*/

void translate(char str[],char exp[])   /*将算术表达式转换成后缀表达式*/
{

      char ch;
      int i = 0,t = 0;
      op.top = -1;
      ch = str[i];                       /*将str的每一个数转换成ch*/
      i++;
      while(ch != '\0')                  /*ch对应不同的符号的时候对应的转换情况*/
      {
             switch(ch)
             {
             case '(':                 /*当是（的时候，将此括号存入栈op*/
                    op.top++;op.data[op.top]=ch;
                    break;
             case ')':
                    while(op.data[op.top] != '(')     /*括号内的转换优先级最高，故先提取表达式*/
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
                    op.top++;            /*恢复可插入位置*/
                    op.data[op.top] = ch;
                    break;
             case '*':
             case '/':
                    while(op.top == '/'||op.top == '*')       /*优先级*/
                    {
                           exp[t] = op.data[op.top];
                           op.top--;
                           t++;
                    }
                    op.top++;
                    op.data[op.top] = ch;
                    break;
             case ' ':                         /*忽略空格，排除误操作*/
                    break;
             default:
                    while(ch >= '0'&&ch <= '9')
                    {
                           exp[t] = ch;t++;
                           ch = str[i];i++;
                    }
                    i--;
                    exp[t] = ' ';              /*分隔操作数，为了美观，也为了以后好分隔操作数，呵呵*/
                    t++;
             }
             ch = str[i];
             i++;
      }
      while(op.top != -1)                   /*得到剩下的部分*/
      {
             exp[t] = op.data[op.top];
             t++;
             op.top--;
      }
      exp[t] = '\0';                         /*表达式结束*/
}
float cal_value(char exp[])
{
      struct
      {
             float data[MaxSize];
             int top;
      }st;                                /*操作数栈*/
      float d;
      char ch;
      int t = 0;
      st.top = -1;
      ch = exp[t];
      t++;
      while(ch != '\0')
      {
             switch(ch)                  /*运算主体*/
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
                             printf("\n\t除0是错误的");
                      }
                      st.top--;
                      break;
              default:
                     d=0;
                     while(ch >= '0'&&ch <= '9')       /*从后缀表达式中获取操作数，#作用在此体现*/
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
int main()                                   /*可以提到前面去*/
{
      char str[MaxSize],exp[MaxSize];       /*str为算术表达式,exps为后缀表达式*/
      printf("请输入一个求值表达式\n");
      printf("表达式:");
      gets(str);                            /*输入一个算术表达式*/
      printf("原表达式是:%s\n",str);
      translate(str,exp);                   /*将算术表达式转换成后追表达式*/
      printf("后缀表达式：%s\n",exp);
      printf("计算结果:%g\n",cal_value(exp));/*通过后缀表达式来求值*/
      system("pause");
      return 0;

}
