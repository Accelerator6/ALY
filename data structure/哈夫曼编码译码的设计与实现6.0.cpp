/*更新*/ 

/*从文件读取数据*/ 
/*
测试数据
Hello World 
1 1 3 3 2 1 1 2 1 3 1
010001011011100000110011100110001111001
*/ 

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

//typedef char ElementType;
typedef char ** HuffmanCode;
typedef struct 
{
	char data; 
	int weight;//节点的权值
	int parent,lchild,rchild;//节点的双亲，左孩子，右孩子的下标 
}HtNode,*HuffmanTree;

typedef struct Node 
{
	char data;
	struct Node *next;	
}Node,*DeNode;

void menu(); 
//创建哈夫曼树HT,n个数据 
bool CreatHuffmanTree(HuffmanTree &HT,int n);

//在哈夫曼树HT中选择两个双亲域为0的权值最小的两个节点 
void Select(HuffmanTree &HT,int rang,int &min1,int &min2);

//根据哈夫曼树求哈夫曼编码
void CreatHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n); 
//翻译报文 
void TraverseData(HuffmanTree HT,HuffmanCode &HC,string data,int n);
//译码 
bool deHuffmanTree(HuffmanTree HT,string code,int n); 
//用链表保存译码信息 
void insert(char data);

	DeNode Head;	
	int flag = 0;
int main()
{	
	Head = new Node;
	Head->next = NULL;
	while(1)
	{
		menu();
	}
	
return 0;
}

void menu()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int n;
	cout << "|-------------------------------------------|"<<endl; 
	cout << "|              哈夫曼编码与译码             |"<<endl;
	cout << "|                 【1】编码                 |"<<endl; 
	cout << "|                 【2】译码                 |"<<endl; 
	cout << "|                 【3】退出                 |"<<endl;
	cout << "|-------------------------------------------|"<<endl;    
	int option;
	cout<<"请选择操作：";
	cin>>option;
	if(1 == option)
	{
		flag = 1;
		cout<<"输入叶子结点的个数:";
		cin>>n;
		if(CreatHuffmanTree(HT,n))
		{
			CreatHuffmanCode(HT,HC,n);
			for(int i = 1;i <= n;i++)
			{
				int j = 0;
				cout<<HT[i].data<<"的编码为：";
				while(HC[i][j] != '\0')
				{
					cout<<HC[i][j];
					j++;
				}
				cout<<endl;
			}
			string data;
		
			int t;
			cout<<"\n【1】文件读取";
			cout<<"\n【2】现在输入"; 
			cout<<"\n请选择操作：";
			cin>>t;
			if(1 == t)
			{
				ifstream infile("数据.txt",ios_base::in);	
				if(!infile.is_open())
				{
					ofstream outfile("数据.txt");
					outfile.close();
					//cerr << "文件打开失败！";
					//exit(0);
				}
				if(infile.peek()==EOF)
				{
					cout << "\n无数据信息\n";
					return;
				}
				else
				{
					getline(infile,data);
				} 
			} 
			if(2 == t)
			{
				cout<<"\n请输入翻译的数据：";
				//cin>>data;
				fflush(stdin);
				getline(cin,data);//输入一行数据 
			}
			cout<<"转码如下：\n";
			TraverseData(HT,HC,data,n); 
		}
	}
	if(2 == option)
	{
		if(0 == flag)
		{
			cout<<"\n请先构建哈夫曼树\n";
			return; 
		}
		string code;
		int t;
		cout<<"\n【1】文件读取";
		cout<<"\n【2】现在输入"; 
		cout<<"\n请选择操作：";
		cin>>t;
		if(1 == t)
		{
			ifstream infile("编码.txt",ios_base::in);	
			if(!infile.is_open())
			{
				ofstream outfile("编码.txt");
				outfile.close();
				//cerr << "文件打开失败！";
				//exit(0);
			}
			if(infile.peek()==EOF)
			{
				cout << "\n无编码信息\n";
				return;
			}
			else
			{
				getline(infile, code);
			} 
		} 
		if(2 == t)
		{
			cout << "请输入编码字符串："; 
			cin>>code;
		}
		
		for(int i = 0;code[i] != '\0';i++)
		{
			if( (code[i] != '0') && (code[i] != '1') )
			{
				cout<<"输入的编码有误！"<<endl;
				return;
			}	
		}
		if(deHuffmanTree(HT,code,n))
		{
			DeNode p = Head->next;
			while(p)
			{
				cout << p->data;
				p = p->next;
			}
			cout<<endl;
		}
		else
		{
			cout<<"\n译码失败！\n"; 
		}
	}
	if(3 == option)
	{
		exit(0);
	}


//			int k = 2*n-1;
//			while(HT[k].lchild != 0)
//			{
//				cout<<HT[k].weight;
//			    k=HT[k].lchild;
//			}
	
}

//创建哈夫曼树HT,n个数据 
bool CreatHuffmanTree(HuffmanTree &HT,int n)
{
	if(n<=1)
	{
		cout<<"创建失败\n";
		return false; 
	}
	int m = 2*n-1;//当n大于1时，n个叶子结点需要2*n-1个节点 
	HT = new HtNode[m+1];//0号单元不用，前面1-n存储叶子结点，后面n-1个位置存放非叶子节点
//---------初始化哈夫曼树----------------------------------------------	
	for(int i = 0;i <= m;i++)
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}

	cout<<"依次输入要存储的数据:";
	//fflush(stdin);
	getchar();
	for(int i = 1;i <= n;i++) 
	{
		HT[i].data = getchar();
	}
	//初始化前n个单元的节点权值 
	cout<<"依次输入n个叶子结点的权值为:";
	for(int i = 1;i <= n;i++) 
	{
		cin>>HT[i].weight;
	}
	HT[0].weight = 9999;
//---------------------------------------------------------------------	
	int min1,min2;
	
	for(int i = n+1;i <= m;i++)//进行n-1次选择 
	{
		//删除两个权值增加一个权值所以传入n-1; 
		//在HT[k]（1<k<n-1）中 
		Select(HT,i-1,min1,min2);
		//从森林中删除min1,min2;把其双亲改为非0 
		HT[min1].parent = i;
		HT[min2].parent = i;
		//合并（将min1,min2的权值和作为一个新权值存入到n之后的单元中，同时记录它的左孩子与右孩子）   
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight = HT[min1].weight+HT[min2].weight;
	}
//	for(int i = 1;i <= m;i++)
//	{
//		cout<<HT[i].weight<<" "<<HT[i].parent<<" "<<HT[i].lchild<<" "<<HT[i].rchild<<endl;	
//		
//	}	
}

//通过n-1次选择（从当前森林中选出双亲为0且权值最小的两个节点下标min1,min2）、
//删除（将min1,min2的双亲改为非0）、

void Select(HuffmanTree &HT,int rang,int &min1,int &min2)
{
	min1 = 0;
	min2 = 0;
	for(int i = 1;i <= rang;i++)
	{
		if( 0 == HT[i].parent )
		{
			if(HT[i].weight < HT[min1].weight)//找到最小权值的的节点位置 
			{
				min1 = i;
			}
		}
		
	} 
	for(int i = 1;i <= rang;i++)
	{
		if( (min1 != i) &&(0 == HT[i].parent))
		{
			if( HT[i].weight < HT[min2].weight )//找到最小权值的的节点位置 
			{
				min2 = i;
			}
		}
	} 	
//	cout <<"qq-----------" <<HT[min1].weight<<"  "<<HT[min2].weight<<endl;	
}
//根据哈夫曼树求哈夫曼编码
void CreatHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)
{
	HC = new char*[n+1];
	char *code = new char[n];
	code[n-1] = '\0';
	int start,now,f;
	for(int i = 1;i <= n;i++)//从叶子开始 
	{
		start = n-1;
		now = i;
		f = HT[i].parent; //f指向节点c的双亲节点 
		while(f != 0)//根节点的双亲为0 
		{
			start--;
			if(HT[f].lchild == now)//用来判断是左孩子还是右孩子 
			{
				code[start] = '0';	
			} 
			else
			{
				code[start] = '1';
			}
			now = f;//向上走 
			f = HT[f].parent;//向上走 
		} 
		HC[i] = new char [n-start];
		strcpy(HC[i],&code[start]);
	}
	delete code;
}
bool deHuffmanTree(HuffmanTree HT,string code,int n)
{	
	int j = 0;
	while(code[j] != '\0')
	{
		int k = 2*n-1;
		while(1)
		{
			//从根结点到叶子节点去匹配，输出最后的那个权值
			if( (code[j] == '0') && (HT[k].lchild != 0) )//如果code[i]是0,并且左孩子不为0，则继续朝叶子结点找。
			{
			    k = HT[k].lchild;
			    j++;
			}
			else if( (code[j] == '1') && (HT[k].rchild != 0) )//如果code[i]是1,并且右孩子不为0，则继续朝叶子结点找。
			{
			    k = HT[k].rchild;	
			    j++;
			}
			else if( (HT[k].rchild == 0) && (HT[k].lchild == 0) )//如果是叶子结点，则把它的权值赋给decode[i]
			{ 
			    insert(HT[k].data);
			    break;
			}
		}
	}
	return true;
}
void TraverseData(HuffmanTree HT,HuffmanCode &HC,string data,int n)
{
	int i = 1;
	//加入保存文件 
	ofstream outfile("编码.txt",ios_base::out);
	while(data[i-1] != '\0')
	{
		int j = 0;
		for(int k = 1;k <= n;k++)
		{
			if( HT[k].data == data[i-1])
			{
				while(HC[k][j] != '\0')
				{
					cout<<HC[k][j];
					outfile<<HC[k][j]; 
					j++;
				}
				break;
			}
		}
		i++;
	}
	cout<<endl;
	outfile.close();
}

void insert(char data)
{
	DeNode p;
	p = Head;
	while(p->next)
	{
		p = p->next;
	}
	DeNode q = new Node;
	q->data = data;
	
	p->next = q;
	q->next = NULL;
}
