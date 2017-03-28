/*����*/ 

/*���ļ���ȡ����*/ 
/*
��������
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
	int weight;//�ڵ��Ȩֵ
	int parent,lchild,rchild;//�ڵ��˫�ף����ӣ��Һ��ӵ��±� 
}HtNode,*HuffmanTree;

typedef struct Node 
{
	char data;
	struct Node *next;	
}Node,*DeNode;

void menu(); 
//������������HT,n������ 
bool CreatHuffmanTree(HuffmanTree &HT,int n);

//�ڹ�������HT��ѡ������˫����Ϊ0��Ȩֵ��С�������ڵ� 
void Select(HuffmanTree &HT,int rang,int &min1,int &min2);

//���ݹ������������������
void CreatHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n); 
//���뱨�� 
void TraverseData(HuffmanTree HT,HuffmanCode &HC,string data,int n);
//���� 
bool deHuffmanTree(HuffmanTree HT,string code,int n); 
//��������������Ϣ 
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
	cout << "|              ����������������             |"<<endl;
	cout << "|                 ��1������                 |"<<endl; 
	cout << "|                 ��2������                 |"<<endl; 
	cout << "|                 ��3���˳�                 |"<<endl;
	cout << "|-------------------------------------------|"<<endl;    
	int option;
	cout<<"��ѡ�������";
	cin>>option;
	if(1 == option)
	{
		flag = 1;
		cout<<"����Ҷ�ӽ��ĸ���:";
		cin>>n;
		if(CreatHuffmanTree(HT,n))
		{
			CreatHuffmanCode(HT,HC,n);
			for(int i = 1;i <= n;i++)
			{
				int j = 0;
				cout<<HT[i].data<<"�ı���Ϊ��";
				while(HC[i][j] != '\0')
				{
					cout<<HC[i][j];
					j++;
				}
				cout<<endl;
			}
			string data;
		
			int t;
			cout<<"\n��1���ļ���ȡ";
			cout<<"\n��2����������"; 
			cout<<"\n��ѡ�������";
			cin>>t;
			if(1 == t)
			{
				ifstream infile("����.txt",ios_base::in);	
				if(!infile.is_open())
				{
					ofstream outfile("����.txt");
					outfile.close();
					//cerr << "�ļ���ʧ�ܣ�";
					//exit(0);
				}
				if(infile.peek()==EOF)
				{
					cout << "\n��������Ϣ\n";
					return;
				}
				else
				{
					getline(infile,data);
				} 
			} 
			if(2 == t)
			{
				cout<<"\n�����뷭������ݣ�";
				//cin>>data;
				fflush(stdin);
				getline(cin,data);//����һ������ 
			}
			cout<<"ת�����£�\n";
			TraverseData(HT,HC,data,n); 
		}
	}
	if(2 == option)
	{
		if(0 == flag)
		{
			cout<<"\n���ȹ�����������\n";
			return; 
		}
		string code;
		int t;
		cout<<"\n��1���ļ���ȡ";
		cout<<"\n��2����������"; 
		cout<<"\n��ѡ�������";
		cin>>t;
		if(1 == t)
		{
			ifstream infile("����.txt",ios_base::in);	
			if(!infile.is_open())
			{
				ofstream outfile("����.txt");
				outfile.close();
				//cerr << "�ļ���ʧ�ܣ�";
				//exit(0);
			}
			if(infile.peek()==EOF)
			{
				cout << "\n�ޱ�����Ϣ\n";
				return;
			}
			else
			{
				getline(infile, code);
			} 
		} 
		if(2 == t)
		{
			cout << "����������ַ�����"; 
			cin>>code;
		}
		
		for(int i = 0;code[i] != '\0';i++)
		{
			if( (code[i] != '0') && (code[i] != '1') )
			{
				cout<<"����ı�������"<<endl;
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
			cout<<"\n����ʧ�ܣ�\n"; 
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

//������������HT,n������ 
bool CreatHuffmanTree(HuffmanTree &HT,int n)
{
	if(n<=1)
	{
		cout<<"����ʧ��\n";
		return false; 
	}
	int m = 2*n-1;//��n����1ʱ��n��Ҷ�ӽ����Ҫ2*n-1���ڵ� 
	HT = new HtNode[m+1];//0�ŵ�Ԫ���ã�ǰ��1-n�洢Ҷ�ӽ�㣬����n-1��λ�ô�ŷ�Ҷ�ӽڵ�
//---------��ʼ����������----------------------------------------------	
	for(int i = 0;i <= m;i++)
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}

	cout<<"��������Ҫ�洢������:";
	//fflush(stdin);
	getchar();
	for(int i = 1;i <= n;i++) 
	{
		HT[i].data = getchar();
	}
	//��ʼ��ǰn����Ԫ�Ľڵ�Ȩֵ 
	cout<<"��������n��Ҷ�ӽ���ȨֵΪ:";
	for(int i = 1;i <= n;i++) 
	{
		cin>>HT[i].weight;
	}
	HT[0].weight = 9999;
//---------------------------------------------------------------------	
	int min1,min2;
	
	for(int i = n+1;i <= m;i++)//����n-1��ѡ�� 
	{
		//ɾ������Ȩֵ����һ��Ȩֵ���Դ���n-1; 
		//��HT[k]��1<k<n-1���� 
		Select(HT,i-1,min1,min2);
		//��ɭ����ɾ��min1,min2;����˫�׸�Ϊ��0 
		HT[min1].parent = i;
		HT[min2].parent = i;
		//�ϲ�����min1,min2��Ȩֵ����Ϊһ����Ȩֵ���뵽n֮��ĵ�Ԫ�У�ͬʱ��¼�����������Һ��ӣ�   
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

//ͨ��n-1��ѡ�񣨴ӵ�ǰɭ����ѡ��˫��Ϊ0��Ȩֵ��С�������ڵ��±�min1,min2����
//ɾ������min1,min2��˫�׸�Ϊ��0����

void Select(HuffmanTree &HT,int rang,int &min1,int &min2)
{
	min1 = 0;
	min2 = 0;
	for(int i = 1;i <= rang;i++)
	{
		if( 0 == HT[i].parent )
		{
			if(HT[i].weight < HT[min1].weight)//�ҵ���СȨֵ�ĵĽڵ�λ�� 
			{
				min1 = i;
			}
		}
		
	} 
	for(int i = 1;i <= rang;i++)
	{
		if( (min1 != i) &&(0 == HT[i].parent))
		{
			if( HT[i].weight < HT[min2].weight )//�ҵ���СȨֵ�ĵĽڵ�λ�� 
			{
				min2 = i;
			}
		}
	} 	
//	cout <<"qq-----------" <<HT[min1].weight<<"  "<<HT[min2].weight<<endl;	
}
//���ݹ������������������
void CreatHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)
{
	HC = new char*[n+1];
	char *code = new char[n];
	code[n-1] = '\0';
	int start,now,f;
	for(int i = 1;i <= n;i++)//��Ҷ�ӿ�ʼ 
	{
		start = n-1;
		now = i;
		f = HT[i].parent; //fָ��ڵ�c��˫�׽ڵ� 
		while(f != 0)//���ڵ��˫��Ϊ0 
		{
			start--;
			if(HT[f].lchild == now)//�����ж������ӻ����Һ��� 
			{
				code[start] = '0';	
			} 
			else
			{
				code[start] = '1';
			}
			now = f;//������ 
			f = HT[f].parent;//������ 
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
			//�Ӹ���㵽Ҷ�ӽڵ�ȥƥ�䣬��������Ǹ�Ȩֵ
			if( (code[j] == '0') && (HT[k].lchild != 0) )//���code[i]��0,�������Ӳ�Ϊ0���������Ҷ�ӽ���ҡ�
			{
			    k = HT[k].lchild;
			    j++;
			}
			else if( (code[j] == '1') && (HT[k].rchild != 0) )//���code[i]��1,�����Һ��Ӳ�Ϊ0���������Ҷ�ӽ���ҡ�
			{
			    k = HT[k].rchild;	
			    j++;
			}
			else if( (HT[k].rchild == 0) && (HT[k].lchild == 0) )//�����Ҷ�ӽ�㣬�������Ȩֵ����decode[i]
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
	//���뱣���ļ� 
	ofstream outfile("����.txt",ios_base::out);
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
